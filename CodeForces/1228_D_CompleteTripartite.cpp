#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[100005];
int par[100005];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    memset(par, 0, sizeof par);
    int c = 0;
    for (int ne : adj[0]) {
        par[ne] += 1;
        c = ne;
    }
    for (int ne : adj[c]) {
        par[ne] += 2;
    }

    bool benar = true;
    int cnt[] = {0, 0, 0, 0};
    for (int i = 0; i < n; i++) {
        cnt[par[i]]++;
    }
    for (int i = 0; i < n; i++) {
        if (par[i] == 0) benar = false;
        for (int ne : adj[i]) {
            if (par[ne] == par[i]) benar = false;
        }
        if (adj[i].size() != n - cnt[par[i]]) benar = false;
    }
    if (benar && cnt[1] > 0 && cnt[2] > 0 && cnt[3] > 0) {
        for (int i = 0; i < n; i++) {
            printf("%d%c", par[i], (i == n - 1 ? '\n' : ' '));
        }
    } else {
        printf("-1\n");
    }
}