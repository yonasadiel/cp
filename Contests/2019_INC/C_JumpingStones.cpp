#include <bits/stdc++.h>
using namespace std;

#define sqr(x) ((x) * (x))

const bool DBG = false;

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

int n, m, q;
set<int> nodes;
vector<int> deleted;
vector<tuple<char, int, int> > op;

struct st_node {
    long long sum;
    int cnt;
    long long prefix;
    long long suffix;
    int left;
    int right;
};

std::ostream& operator<<(std::ostream &o, st_node node)
{
    return o << "(sum=" << node.sum << ",cnt=" << node.cnt << "," << node.prefix << "," << node.suffix << "(" << node.left << ":" << node.right << ")" << ")";
}

int joinUpdate(int prev, int next) {
    return next;
}

st_node updateNode(st_node prev, int u) {
    if (u == 1) {
        prev.sum = 0LL;
        prev.cnt = 0;
        prev.prefix = 0;
        prev.suffix = 0;
    } else {
        prev.sum = 1LL;
        prev.cnt = 1;
        prev.prefix = 1;
        prev.suffix = 1;
    }
    return prev;
}

st_node joinNode(st_node left, st_node right) {
    st_node res;
    int left_size = left.right - left.left + 1;
    int right_size = right.right - right.left + 1;
    res.sum = left.sum + right.sum - sqr(left.suffix) - sqr(right.prefix) + sqr(left.suffix + right.prefix);
    res.cnt = left.cnt + right.cnt;
    res.prefix = left.prefix == left_size ? left_size + right.prefix : left.prefix;
    res.suffix = right.suffix == right_size ? right_size + left.suffix : right.suffix;
    res.left = left.left;
    res.right = right.right;
    return res;
}

int main() {
    scanf("%d%d%d", &n, &m, &q);

    int x;
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        deleted.push_back(x);
        nodes.insert(x);
        nodes.insert(x + 1);
        nodes.insert(x - 1);
    }
    scanf("\n");

    char ops[5];
    int a, b;
    for (int i = 0; i < q; i++) {
        scanf("%s", &ops);
        if (strcmp(ops, "go") == 0) {
            scanf("%d%d", &a, &b);
            nodes.insert(a);
            nodes.insert(b);

            op.push_back(make_tuple('g', a, b));
        } else if (strcmp(ops, "rem") == 0) {
            scanf("%d", &x);
            nodes.insert(x);
            nodes.insert(x - 1);
            nodes.insert(x + 1);

            op.push_back(make_tuple('r', x, -1));
        } else {
            scanf("%d", &x);
            nodes.insert(x);
            nodes.insert(x - 1);
            nodes.insert(x + 1);

            op.push_back(make_tuple('a', x, -1));
        }
    }

    map<int, int> compress;
    int translated = 0;
    for (auto it : nodes) {
        compress[it] = ++translated;
    }

    vector<st_node> initialNodes;
    st_node defaultNode;
    for (int i = 0; i < nodes.size(); i++) {
        defaultNode.sum = 0;
        defaultNode.cnt = 0;
        defaultNode.prefix = 0;
        defaultNode.suffix = 0;
        defaultNode.left = i;
        defaultNode.right = i;
        initialNodes.push_back(defaultNode);
    }
    defaultNode.left = -1;
    defaultNode.right = -1;
    segment_tree<st_node, int> st(initialNodes, defaultNode, 0, joinUpdate, updateNode, joinNode);

    for (int d : deleted) {
        int dd = compress[d];
        // if (DBG) printf("remove %d\n", dd);
        st.update(dd - 1, dd, -1);
    }

    for (int i = 0; i < q; i++) {
        char op_c = get<0>(op[i]);
        if (op_c == 'g') {
            int a = compress[get<1>(op[i])];
            int b = compress[get<2>(op[i])];
            int _a = min(a, b) - 1;
            int _b = max(a, b) - 1;
            if (DBG) printf("query %d %d\n", _a, _b + 1);
            printf("%lld\n", st.query(_a, _b + 1).sum);
        } else if (op_c == 'r') {
            int a = compress[get<1>(op[i])];
            if (DBG) printf("remove %d\n", a);
            st.update(a - 1, a, -1);
        } else {
            int a = compress[get<1>(op[i])];
            if (DBG) printf("add %d\n", a);
            st.update(a - 1, a, 1);
        }
        // st.debug();
    }
}