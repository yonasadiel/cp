#include <bits/stdc++.h>
using namespace std;

int n, m;
long long a[200005];
int parent[200005];
vector<pair<long long, pair<int, int> > > edges;

int find_parent(int a) {
    if (parent[a] == a) return a;
    int pa = find_parent(parent[a]);
    parent[a] = pa;
    return pa;
}

int solve() {
    edges.clear();
    int mia = 0;
    for (int i=0; i<n; i++) {
        parent[i] = i;
        scanf("%lld", &a[i]);
        if (a[i] < a[mia]) {
            mia = i;
        }
    }
    for (int i=0; i<n; i++) {
        if (i != mia) {
            // printf("-%lld %d %d\n", a[i] + a[mia], i, mia);
            edges.push_back(make_pair(a[i] + a[mia], make_pair(i, mia)));
        }
    }
    for (int i=0; i<m; i++) {
        int u, v; long long w;
        scanf("%d%d%lld", &u, &v, &w);
        u--; v--;
        edges.push_back(make_pair(w, make_pair(u, v)));
    }
    sort(edges.begin(), edges.end());
    long long cost = 0;
    int take = 0;
    for (const pair<long long, pair<int, int> >& x : edges) {
        int pa = find_parent(x.second.first);
        int pb = find_parent(x.second.second);
        // printf("%d:%d <-> %d:%d\n", x.second.first, pa, x.second.second, pb);
        if (pa != pb) {
            cost += x.first;
            parent[pa] = pb;
        }
    }
    printf("%lld\n", cost);

}

int main () {
    while (scanf("%d%d", &n, &m) == 2) {
        solve();
    }
}