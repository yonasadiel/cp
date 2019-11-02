#include <bits/stdc++.h>
using namespace std;

// https://github.com/jauhararifin/cp/blob/master/template/segment_tree.cpp

/**
 * T : node type
 * U : update type
 * joinUpdate : when two update joined
 * updateNode : when node updated using update type
 * joinNode : join node with node
 */
template <typename T, typename U>
class segment_tree {
public:
    segment_tree(int n, T defaultNode, U defaultUpdate, U (*joinUpdate)(U, U), T (*updateNode)(T, U), T (*joinNode)(T, T)) {
        vector<T> temp;
        temp.resize(n, defaultNode);
        init(temp, defaultNode, defaultUpdate, joinUpdate, updateNode, joinNode);
    }

    segment_tree(vector<T> arr, T defaultNode, U defaultUpdate, U (*joinUpdate)(U, U), T (*updateNode)(T, U), T (*joinNode)(T, T)) {
        init(arr, defaultNode, defaultUpdate, joinUpdate, updateNode, joinNode);
    }

    ~segment_tree() {
        delete [] needUpdate;
        free(stree);
        free(utree);
    }

    void update(int left, int right, U val) {
        rec_update_segtree(1, left, right-1, 0, n - 1, val);
    }

    T query(int left, int right) {
        return rec_query(1, left, right-1, 0, n - 1);
    }

    void debug() {
        rec_debug(1, 0, n-1, 0);
    }

    int n;
    bool* needUpdate;
    T* stree;
    U* utree;
    T defaultNode;
    U defaultUpdate;
    U (*joinUpdate)(U, U);
    T (*updateNode)(T, U);
    T (*joinNode)(T, T);

private:
    void rec_debug(int node, int left, int right, int level) {
        for (int i = 0; i < 4*level; i++) cout<<" ";
        cout<<stree[node]<<" update: "<<utree[node]<<endl;
        if (left < right) {
            rec_debug(2*node, left, (left+right)/2, level+1);
            rec_debug(2*node+1, (left+right)/2+1, right, level+1);
        }
    }

    void init(vector<T> arr, T defaultNode, U defaultUpdate, U (*joinUpdate)(U, U), T (*updateNode)(T, U), T (*joinNode)(T, T)) {
        this->n = arr.size();
        this->defaultNode = defaultNode;
        this->defaultUpdate = defaultUpdate;
        this->joinUpdate = joinUpdate;
        this->updateNode = updateNode;
        this->joinNode = joinNode;

        needUpdate = new bool[4*n+1];
        void* streeP = malloc((4*n+1) * sizeof(T)); stree = (T*) streeP;
        void* utreeP = malloc((4*n+1) * sizeof(U)); utree = (U*) utreeP;
        for (int i = 0; i < 4*n+1; i++) {
            needUpdate[i] = 0;
            memcpy(stree + i, &defaultNode, sizeof(defaultNode));
            memcpy(utree + i, &defaultUpdate, sizeof(defaultUpdate));
        }

        init_segment_tree(1, 0, n-1, arr);
    }

    T init_segment_tree(int node, int left, int right, vector<T>& arr) {
        if (left > right || left < 0 || right >= n) return defaultNode;
        if (left == right)
            return stree[node] = arr[left];
        else
            return stree[node] = joinNode(init_segment_tree(2*node, left, (left+right)/2, arr), init_segment_tree(2*node+1, (left+right)/2+1, right, arr));
    }

    T rec_query(int node, int left, int right, int l, int r) {
        if (node > 4*n || r < left || l > right) return defaultNode;

        if (joinUpdate && needUpdate[node]) {
            stree[node] = updateNode(stree[node], utree[node]);
            needUpdate[node] = 0;
            if (node*2 <= 4*n) {
                utree[node*2] = needUpdate[node*2] ? joinUpdate(utree[node*2], utree[node]) : utree[node];
                needUpdate[node*2] = 1;
            }
            if (node*2+1 <= 4*n) {
                utree[node*2+1] = needUpdate[node*2+1] ? joinUpdate(utree[node*2+1], utree[node]) : utree[node];
                needUpdate[node*2+1] = 1;
            }
        }

        if (l < left || r > right)
            return joinNode(rec_query(2*node, left, right, l, (l+r)/2), rec_query(2*node+1, left, right, (l+r)/2+1, r));
        else
            return stree[node];
    }

    T rec_update_segtree(int node, int left, int right, int l, int r, U val) {
        if (node > 4*n) return defaultNode;

        if (joinUpdate && needUpdate[node]) {
            stree[node] = updateNode(stree[node], utree[node]);
            needUpdate[node] = 0;
            if (node*2 <= 4*n) {
                utree[node*2] = needUpdate[node*2] ? joinUpdate(utree[node*2], utree[node]) : utree[node];
                needUpdate[node*2] = 1;
            }
            if (node*2+1 <= 4*n) {
                utree[node*2+1] = needUpdate[node*2+1] ? joinUpdate(utree[node*2+1], utree[node]) : utree[node];
                needUpdate[node*2+1] = 1;
            }
        }

        if (r < left || l > right) return stree[node];

        if (l < left || r > right) {
            stree[node] = joinNode(rec_update_segtree(2*node, left, right, l, (l+r)/2, val), rec_update_segtree(2*node+1, left, right, (l+r)/2+1, r, val));
        } else {
            stree[node] = updateNode(stree[node], val);
            if (node*2 <= 4*n) {
                utree[node*2] = needUpdate[node*2] ? joinUpdate(utree[node*2], val) : val;
                needUpdate[node*2] = 1;
            }
            if (node*2+1 <= 4*n) {
                utree[node*2+1] = needUpdate[node*2+1] ? joinUpdate(utree[node*2+1], val) : val;
                needUpdate[node*2+1] = 1;
            }
        }
        return stree[node];
    }
};

// sample usage for SPOJ RANGESUM

int n, q;
int x;
int l, r;

void solve() {
    scanf("%d", &n);

    // each node described as (distinct value, max value)
    segment_tree<int, int>* st =
        new segment_tree<int, int>(
            10000000, 0, 0,
            // join update
            *[](int old_update, int new_update) -> int {
                return new_update;
            },
            // apply update
            *[](int node, int update) -> int {
                return update;
            },
            // join node
            *[](int node1, int node2) -> int {
                return max(node1, node2);
            }
        );

    int p = 0;
    for (int i=0; i<n; i++) {
        scanf("%d%d", &l, &r);
        st->update(l, r, p++);
    }

    set<int> s;
    for (int i=1; i<=10000000; i++) {
        s.insert(st->query(i, i));
    }
    printf("%d\n", s.size());
    delete st;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
}