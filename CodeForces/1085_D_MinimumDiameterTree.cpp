#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, s;
vector<int> adj[100005];
int dist[100005];
int pref[100005];

int solve() {
    for (int i=0; i<n; i++) adj[i].clear();
    for (int i=0; i<n-1; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }

    int leaf = 0;
    for (int i=0; i<n; i++) {
        if (adj[i].size() == 1) {
            leaf++;
        }
    }

    printf("%.9lf\n", s * 2.0 / leaf);
}

int main() {
    while (scanf("%d%d", &n, &s) == 2) {
        solve();
    }
}