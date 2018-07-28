#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[2005];
int b[2005];

vector<int> pre;
vector<int> post;
vector<int> adj[2005];
int label[2005];

void traverse(int node) {
    pre.push_back(node);
    if (a[node]) { traverse(a[node]); }
    if (b[node]) { traverse(b[node]); }
    post.push_back(node);
}

void dfs(int node, int l) {
    label[node] = l;
    for (int a : adj[node])
        if (label[a] == -1) dfs(a, l);
}

void solve(int tc) {
    pre.clear();
    post.clear();
    for (int i=0; i<2005; i++) adj[i].clear();
    memset(label, -1, sizeof label);

    scanf("%d%d", &n, &k);
    for (int i=1; i<=n; i++) {
        scanf("%d%d", &a[i], &b[i]);
    }

    traverse(1);

    // for (int a : pre) printf(" %2d", a); printf("\n");
    // for (int a : post) printf(" %2d", a); printf("\n");

    for (int i=0; i<pre.size(); i++) {
        adj[pre[i]].push_back(post[i]);
        adj[post[i]].push_back(pre[i]);
    }

    int l = 1;
    for (int i=1; i<=n; i++) {
        if (label[i] == -1) {
            dfs(i, l);
            l++;
        }
    }

    printf("Case #%d:", tc);
    if (l > k) {
        for (int i=1; i<=n; i++) { printf(" %d", ((label[i] - 1) % k) + 1); }
        printf("\n");
    } else {
        printf(" Impossible\n");
    }
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i=1; i<=t; i++) {
        solve(i);
    }
}