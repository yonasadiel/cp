#include <bits/stdc++.h>
using namespace std;

int n, q, l;
vector<vector<int>> adj;
vector<int> height;

int timer;
vector<int> tin, tout;
vector<vector<int>> up;

void dfs(int v, int p) {
    height[v] = height[p] + 1;
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v);
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess(int root) {
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1));
    height[root] = 0;
    dfs(root, root);
}

vector<int> ancestor;
vector<bool> visited;

int find_set(int a) {
    if (ancestor[a] == a) return a;
    return ancestor[a] = find_set(ancestor[a]);
}

void union_sets(int a, int b) {
    int pa = find_set(a);
    int pb = find_set(b);
    ancestor[pa] = pb;
}
int dicari;
int cost[100000];

set<int> g;

int dfs(int v)
{
    visited[v] = true;
    int ans = 0;
    for (int u : adj[v]) {
        if (!visited[u]) {
            ans += dfs(u);
            union_sets(v, u);
            ancestor[find_set(v)] = v;
            ancestor[v] = v;
        }
    }
    for (int other_node : g) {
        if (visited[other_node]) {
            int c = ancestor[find_set(other_node)];
            cost[v + other_node - dicari] = height[v] - height[c] + height[other_node] - height[c];
        }
    }
    if (visited[dicari]) {
        int c = ancestor[find_set(dicari)];
        cost[v + dicari - dicari] = height[v] - height[c] + height[dicari] - height[c];
    }
    return ans;
}

int countdist(int a, int b) {
    int c = lca(a, b);
    return (height[a] - height[c]) + (height[b] - height[c]);
}

int main() {
    scanf("%d%d", &n, &q);
    for (int i=0; i<n; i++) {
        adj.push_back(vector<int>());
        height.push_back(0);
    }
    for (int i=0; i<n-1; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }

    for (int i = 0; i<n; i++) {
        int x;
        scanf("%d", &x);
        if (x) g.insert(i);
    }

    preprocess(0);
    int dist_run = 0;
    for (int a : g)
        for (int b : g)
            if (a < b)
                dist_run += countdist(a, b);

    ancestor.resize(n);

    for (int i = 0; i<q; i++) {
        int op;
        scanf("%d", &op);
        if (op == 1) {
            printf("%d\n", dist_run);
        } else {
            int x;
            scanf("%d", &x); x--;
            dicari = x;
            for (int i=0; i<n; i++) { ancestor[i] = i; }
            memset(cost, 0, sizeof cost);
            if (g.find(x) == g.end()) {
                visited.clear();
                visited.assign(n, false);
                dfs(0);
                int tcost = 0;
                for (int gx : g) tcost += cost[gx];
                dist_run += tcost;

                g.insert(x);
            } else {
                g.erase(x);
                visited.clear();
                visited.assign(n, false);
                dfs(0);
                int tcost = 0;
                for (int gx : g) tcost += cost[gx];
                dist_run -= tcost;
            }
        }
    }
}