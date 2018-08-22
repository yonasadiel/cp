#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define mp make_pair
#define pii pair<int, int>
using namespace std;

const int dr[] = {0, 1, -1, 0, 1, 1, -1, -1};
const int dc[] = {1, 0, 0, -1, 1, -1, 1, -1};

bool in_bound(pii _p, int _max_fi, int _max_se) {
    return _p.fi >= 0 && _p.fi < _max_fi && _p.se >= 0 && _p.se < _max_se;
}

int n, m;
int u, v;
int maxv;
vector<int> cur;
int adj[25][25];

void find(int pos) {
    maxv = max(maxv, (int) cur.size());
    if (pos == n) return;

    find(pos+1);

    bool valid = true;
    for (int take : cur) {
        if (adj[take][pos] == 0)
            valid = false;
    }

    if (valid) {
        cur.push_back(pos);
        find(pos+1);
        cur.pop_back();
    }
}

int main() {
    memset(adj, 0, sizeof adj);
    scanf("%d%d", &n, &m);
    for (int i=0; i<m; i++) {
        scanf("%d%d", &u, &v);
        u--; v--;
        adj[u][v] = adj[v][u] = 1;
    }

    maxv = 0;
    cur.clear();

    find(0);
    printf("%d\n", maxv);
}