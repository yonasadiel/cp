#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> adj[100005];
int parent[100005];
int sz[100005];

int dfs(int node, int par) {
    parent[node] = par;
    sz[node] = 1;
    for (int neig : adj[node]) {
        if (neig != par) {
            sz[node] += dfs(neig, node);
        }
    }
    return sz[node];
}

void flip(int node) {
    printf("flip %d\n", node + 1);
    for (int neig : adj[node]) {
        if (neig != parent[node]) {
            flip(neig);
        }
    }
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    sz[0] = dfs(0, 0);

    for (int i = 0; i < n; i++) {
        if (sz[i] == k || n - sz[i] == k) {
            flip(i);
            printf("cut %d %d\n", i + 1, parent[i] + 1);
            return 0;
        }
    }
    printf("-1\n");
}