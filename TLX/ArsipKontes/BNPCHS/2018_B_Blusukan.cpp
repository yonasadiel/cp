#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

int parent[2005];
int cnt[2005];
ll fact[4000005];

void calc_fact() {
    fact[0] = 1LL;
    for (int i=1; i<4000005; i++) {
        fact[i] = fact[i-1] * i;
        fact[i] %= MOD;
    }
}

int find_parent(int x) {
    if (parent[x] == x) return x;
    int px = find_parent(parent[x]);
    parent[x] = px;
    return px;
}

void solve(int tc) {
    int n, m, a, b;
    scanf("%d%d", &n, &m);
    for (int i=0; i<=n; i++) { parent[i] = i; }
    for (int i=0; i<m; i++) {
        scanf("%d%d",&a, &b);
        int pa = find_parent(a);
        int pb = find_parent(b);
        parent[pa] = pb;
    }

    memset(cnt, 0, sizeof cnt);
    for (int i=1; i<=n; i++) {
        int pa = find_parent(i);
        cnt[pa]++;
    }

    ll ans = 1LL;
    int cnt_pulau = 0;
    for (int i=1; i<=n; i++) {
        if (cnt[i] > 1) {
            ll jalan = 1LL * cnt[i] * (cnt[i]-1) / 2;
            ans *= fact[jalan];
            ans %= MOD;
            cnt_pulau++;
        }
    }
    ans *= fact[cnt_pulau];
    ans %= MOD;
    printf("Kasus #%d: %lld\n", tc, ans);
}

int main() {
    int t;
    calc_fact();
    scanf("%d", &t);
    for (int i=1; i<=t; i++) {
        solve(i);
    }
}