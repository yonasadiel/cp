#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define mp make_pair
#define MOD 1000000007
using namespace std;

int n;
vector<int> adj[100005];
ll deg[100005];
ll gatau[100005];

ll pangkat(ll a, ll b) {
    ll ans = 1;
    for (int i=0; i<64; i++) {
        if (b & (1LL << i)) {
            ans *= a;
            ans %= MOD;
        }
        a *= a;
        a %= MOD;
    }
    return ans;
}

int main() {
    // printf("%lld\n", pangkat(2, MOD-2));
    memset(deg, 0, sizeof deg);
    scanf("%d", &n);
    for (int i=0; i<n-1; i++) {
        int x,y;
        scanf("%d%d", &x, &y);
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
        deg[x]++;
        deg[y]++;
    }
    for (int i=0; i<n; i++) {
        gatau[i] = 0;
        if (deg[i] >= 3)
            gatau[i] = (deg[i]-1)*(deg[i]-2)/2;
        gatau[i] %= MOD;
    }

    ll ans = 0;
    for (int x=0; x<n; x++) {
        ll adjs = adj[x].size();
        if (adjs >= 4) {
            vector<ll> dikali;
            for (int y : adj[x]) {
                if (gatau[y] > 0) dikali.push_back(gatau[y]);
            }

            ll temp = 0;
            for (ll kali : dikali) {
                temp += kali;
            }

            temp *= temp;
            temp %= MOD;

            for (ll kali : dikali) {
                temp -= (kali * kali) % MOD;
                temp += MOD;
                temp %= MOD;
            }

            // inverse temp /= 2;
            temp *= pangkat(2, MOD-2);
            temp %= MOD;

            temp *= ((adjs-2) * (adjs-3))/2;
            temp %= MOD;

            ans += temp;
            ans %= MOD;
        }
    }

    printf("%lld\n", ans);
}
