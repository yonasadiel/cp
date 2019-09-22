#include <bits/stdc++.h>
#define fi first
#define se second.first
#define th second.second
#define pii pair<int, int>
#define piii pair<int, pii>
using namespace std;

piii p[100005];
vector<pair<int, pii> > edges;

int parent[100005];
int find_parent(int x) {
    if (parent[x] == x) return x;
    int px = find_parent(parent[x]);
    parent[x] = px;
    return parent[x];
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &p[i].fi, &p[i].se);
        p[i].th = i;
        parent[i] = i;
    }
    sort(p, p + n, [](const piii& a, const piii& b) { return a.fi < b.fi; });
    for (int i = 0; i < n - 1; i++) {
        edges.push_back(make_pair(p[i + 1].fi - p[i].fi, make_pair(p[i].th, p[i + 1].th)));
    }

    sort(p, p + n, [](const piii& a, const piii& b) { return a.se < b.se; });
    for (int i = 0; i < n - 1; i++) {
        edges.push_back(make_pair(p[i + 1].se - p[i].se, make_pair(p[i].th, p[i + 1].th)));
    }

    sort(edges.begin(), edges.end());
    long long ans = 0;
    for (int i = 0; i < edges.size(); i++) {
        piii &edge = edges[i];
        int pa = find_parent(edge.se);
        int pb = find_parent(edge.th);
        if (pa != pb) {
            ans += edge.fi;
            parent[pa] = pb;
        }
    }
    printf("%lld\n", ans);
}
