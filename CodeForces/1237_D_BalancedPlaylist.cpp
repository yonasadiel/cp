#include <bits/stdc++.h>
using namespace std;

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

int n;
double a[100005];
int ans[100005];

int main() {
    scanf("%d", &n);

    int m = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lf", &a[i]);
        if (a[i] > a[m]) m = i;
    }

    segment_tree<double, double> st(4 * n, 0, 0,
        [](double prev, double upd) {
            return upd;
        },
        [](double node, double upd) {
            return upd;
        },
        [](double left, double right) {
            return max(left, right);
        }
    );
    memset(ans, -1, sizeof ans);
    int head = -1, tail = 0;
    double curMax = 0;
    for (int j = 0; j < 4 * n; j++) {
        int i = (m + j + 1) % n;
        while (tail <= head && a[i] < curMax / 2) {
            if (ans[(m + tail + 1) % n] == -1) {
                ans[(m + tail + 1) % n] = j - tail;
                // printf("1 tail %d head %d curMax %.0lf\n", tail, head, curMax);
            }
            tail++;
            curMax = tail <= head ? st.query(tail, head + 1) : 0;
            // printf("2 tail %d head %d curMax %.0lf\n", tail, head, curMax);
        }
        head++;
        st.update(head, head + 1, a[i]);
        curMax = max(curMax, a[i]);
        // printf("3 tail %d head %d curMax %.0lf\n", tail, head, curMax);
    }

    for (int i = 0; i < n; i++) {
        printf("%d%c", ans[i], i == n - 1 ? '\n' : ' ');
    }
}
