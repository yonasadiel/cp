#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int, int>
#define mp make_pair
using namespace std;

const bool debug = false;

int a, b;
vector<int> u,v;
int n, m;
int h[200005];
map<pii, vector<pii> > adj;
map<pii, int> par;
map<pii, bool> visited;

int main() {
    scanf("%d%d", &n, &m);
    for (int i=0; i<n; i++) {
        scanf("%d", &h[i]);
    }
    for (int i=0; i<m; i++) {
        scanf("%d%d", &a, &b);
        a--; b--;
        if (h[a] > h[b]) {
            u.push_back(b);
            v.push_back(a);
        } else if (h[b] > h[a]) {
            u.push_back(a);
            v.push_back(b);
        }
    }
    m = u.size();
    for (int i=0; i<m; i++) {
        int diff = h[v[i]] - h[u[i]];
        adj[mp(u[i], diff)].push_back(mp(v[i], diff));
    }

    for (auto k : adj) {
        par[k.fi] = 0;
    }

    for (int i=0; i<m; i++) {
        par[mp(v[i], h[v[i]] - h[u[i]])]++;
    }

    //                  height   dist  node
    priority_queue<pair<int,  pair<int, pii> > > pq;
    for (auto k : adj) {
        if (par[k.fi] == 0) {
            pq.push(mp(-h[k.fi.fi], mp(1, k.fi)));
        }
        visited[k.fi] = false;
    }

    int maxdist = 0;
    while (!pq.empty()) {
        pair<int, pair<int, pii> > pp = pq.top();
        pair<int, pii> cur = pp.se; pq.pop();

        if (debug) {
            printf("popping pq {%d,%d,{%d,%d}}\n", pp.fi, pp.se.fi, pp.se.se.fi, pp.se.se.se);
        }

        for (pii ne : adj[cur.se]) {
            if (!visited[ne]) {
                pq.push(mp(-h[ne.fi], mp(cur.fi + 1, ne)));
                visited[ne] = true;
                maxdist = max(maxdist, cur.fi + 1);
            }
        }
    }

    if (maxdist == 1) maxdist = 0;
    printf("%d\n", maxdist);

}
