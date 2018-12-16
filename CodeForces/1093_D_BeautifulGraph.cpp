#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

long long two_power_to[300005];
int color[300005];
vector<int> adj[300005];

void solve() {

    int n, m;
    int u, v;

    scanf("%d%d", &n, &m);
    for (int i=0; i<m; i++) {
        scanf("%d%d", &u, &v);
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    long long ans = 1LL;
    bool bipartite = true;
    for (int i = 0; i < n && bipartite; i++) {
        if (color[i] == -1) {
            int count[] = {0, 0, 0};
            color[i] = 0; count[0]++;
            queue<int> q;
            q.push(i);
            while (!q.empty() && bipartite) {
                int cur = q.front();
                q.pop();
                for (int next : adj[cur]) {
                    if (color[next] == -1) {
                        color[next] = 1 ^ color[cur];
                        count[color[next]]++;
                        q.push(next);
                    } else if (color[next] == color[cur]) {
                        bipartite = false;
                    }
                }
            }
            if (count[0] + count[1] == 1) {
                ans *= 3;
                ans %= MOD;
            } else {
                long long poss = two_power_to[count[0]] + two_power_to[count[1]];
                ans *= (poss) % MOD;
                ans %= MOD;
            }

            while (!q.empty()) {
                q.pop();
            }
        }
    }
    if (bipartite) {
        printf("%lld\n", ans);
    } else {
        printf("0\n");
    }
    for (int i = 0; i < n;i++) {
        adj[i].clear();
    }
    memset(color, -1, n * sizeof(int));
}

int main() {
    memset(color, -1, sizeof color);
    two_power_to[0] = 1;
    for (int i = 1; i <= 300000; i++) {
        two_power_to[i] = 2 * two_power_to[i - 1];
        two_power_to[i] %= MOD;
    }
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
}