#include <bits/stdc++.h>
#define MAX 100000
using namespace std;

class SegTree {
private:
    int tree[MAX] = {0};
    int lazy[MAX] = {0};

    void updateRangeUtil(int si, int ss, int se, int us, int ue, int diff) {
        if (lazy[si] != 0) {
            tree[si] += (se-ss+1)*lazy[si];

            if (ss != se) {
                lazy[si*2 + 1]   += lazy[si];
                lazy[si*2 + 2]   += lazy[si];
            }

            lazy[si] = 0;
        }

        if (ss>se || ss>ue || se<us)
            return ;

        if (ss>=us && se<=ue) {
            tree[si] += (se-ss+1)*diff;

            if (ss != se) {
                lazy[si*2 + 1]   += diff;
                lazy[si*2 + 2]   += diff;
            }
            return;
        }

        int mid = (ss+se)/2;
        updateRangeUtil(si*2+1, ss, mid, us, ue, diff);
        updateRangeUtil(si*2+2, mid+1, se, us, ue, diff);

        tree[si] = tree[si*2+1] + tree[si*2+2];
    }

    int getSumUtil(int ss, int se, int qs, int qe, int si) {
        if (lazy[si] != 0) {
            tree[si] += (se-ss+1)*lazy[si];

            if (ss != se) {
                lazy[si*2+1] += lazy[si];
                lazy[si*2+2] += lazy[si];
            }

            lazy[si] = 0;
        }

        if (ss>se || ss>qe || se<qs)
            return 0;

        if (ss>=qs && se<=qe)
            return tree[si];

        int mid = (ss + se)/2;
        return getSumUtil(ss, mid, qs, qe, 2*si+1) +
            getSumUtil(mid+1, se, qs, qe, 2*si+2);
    }

    void constructSTUtil(int arr[], int ss, int se, int si) {
        if (ss > se)
            return ;

        if (ss == se) {
            tree[si] = arr[ss];
            return;
        }

        int mid = (ss + se)/2;
        constructSTUtil(arr, ss, mid, si*2+1);
        constructSTUtil(arr, mid+1, se, si*2+2);

        tree[si] = tree[si*2 + 1] + tree[si*2 + 2];
    }

public:
    SegTree(int arr[], int n) {
        constructSTUtil(arr, 0, n-1, 0);
    }

    void updateRange(int n, int us, int ue, int diff) {
        updateRangeUtil(0, 0, n-1, us, ue, diff);
    }

    int getSum(int n, int qs, int qe) {
        if (qs < 0 || qe > n-1 || qs > qe) {
            printf("Invalid Input");
            return -1;
        }

        return getSumUtil(0, n-1, qs, qe, 0);
    }
};

int n,m;
int u,v,k;
int tree_parent[100005];
int set_parent[100005];
vector<int> child[100005];
vector<int> path[100005];

void dfs(int node, int sparent) {
    set_parent[node] = sparent;
    path[sparent].push_back(node);
    if (child[node].size() > 0) {
        dfs(child[node][0], sparent);
        for (int i=1; i<child[node].size(); i++) {
            dfs(child[node][i], child[node][i]);
        }
    }
}

int main() {
    memset(tree_parent, -1, sizeof tree_parent);
    scanf("%d%d", &n, &m);
    for (int i=0; i<n-1; i++) {
        scanf("%d%d", &u, &v);
        tree_parent[u] = v;
        child[v].push_back(u);
    }

    for (int i=0; i<n; i++) {
        if (tree_parent[i] == -1)
            dfs(i, i);
    }

    for (int i=0; i<m; i++) {
        scanf("%d%d%d", &u, &v, &k);
        int pu = set_parent[u];
        int pv = set_parent[v];
    }

    int arr[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(arr)/sizeof(arr[0]);

    // Build segment tree from given array
    SegTree *st = new SegTree(arr, n);

    // Print sum of values in array from index 1 to 3
    printf("Sum of values in given range = %d\n",
           st->getSum(n, 1, 3));

    // Add 10 to all nodes at indexes from 1 to 5.
    st->updateRange(n, 1, 5, 10);

    // Find sum after the value is updated
    printf("Updated sum of values in given range = %d\n",
            st->getSum( n, 1, 3));

    return 0;
}