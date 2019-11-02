#include <bits/stdc++.h>
using namespace std;

int n;
int x[5005], y[5005];
long long c[5005], k[5005];

int parent[5005];

vector<pair<long long, pair<int, int> > > edges;
vector<bool> marks;

int find_parent(int x) {
    if (parent[x] == x) return x;
    int px = find_parent(parent[x]);
    parent[x] = px;
    return px;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &x[i], &y[i]);
        parent[i] = i;
    }
    long long ccost = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &c[i]);
        ccost += c[i];
    }
    for (int i = 0; i < n; i++) scanf("%lld", &k[i]);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            long long cost = (k[i] + k[j]) * (abs(x[i] - x[j]) + abs(y[i] - y[j]));
            edges.push_back(make_pair(cost, make_pair(i, j)));
            marks.push_back(false);
        }
    }
    sort(edges.begin(), edges.end());
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        int pu = find_parent(u);
        int pv = find_parent(v);

        if (pu != pv) {
            int pmin = pv, pmax = pu;
            if (c[pu] < c[pv]) {
                pmin = pu;
                pmax = pv;
            }

            if (ccost - c[pmax] + edges[i].first < ccost) {
                ccost -= c[pmax];
                ccost += edges[i].first;
                parent[pmax] = pmin;
                marks[i] = true;
            }
        }
    }
    printf("%lld\n", ccost);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (parent[i] == i) {
            cnt++;
        }
    }
    printf("%d\n", cnt);
    for (int i = 0; i < n; i++) {
        if (parent[i] == i) {
            cnt--;
            printf("%d%c", i + 1, cnt == 0 ? '\n' : ' ');
        }
    }
    int cnt_edges = 0;
    for (int i = 0; i < marks.size(); i++) {
        if (marks[i]) {
            cnt_edges++;
        }
    }
    printf("%d\n", cnt_edges);
    for (int i = 0; i < marks.size(); i++) {
        if (marks[i]) {
            printf("%d %d\n", edges[i].second.first + 1, edges[i].second.second + 1);
        }
    }
}