#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

long long dp[100005][5];
// 0 : 1 black
// 1 : 2 black
// 2 : 1 white
// 3 : 2 white

long long tambah(int n) {
    long long ans = 0LL;
    for (int l = 0; l < 4; l++) {
        ans += dp[n][l];
        ans %= MOD;
    }
    return ans;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    dp[1][0] = 1LL;
    dp[1][1] = 0LL;
    dp[1][2] = 1LL;
    dp[1][3] = 0LL;
    for (int i = 2; i <= 100000; i++) {
        dp[i][0] = (dp[i-1][2] + dp[i - 1][3]) % MOD;
        dp[i][1] = dp[i-1][0];
        dp[i][2] = (dp[i-1][0] + dp[i - 1][1]) % MOD;
        dp[i][3] = dp[i-1][2];
    }

    long long ans = 0LL;
    if      (n >= 2) { ans += tambah(n); }
    else if (n == 1) { ans += 2LL; }
    ans %= MOD;

    if      (m >= 2) { ans += tambah(m); }
    else if (m == 1) { ans += 2LL; }
    ans %= MOD;

    ans = (ans - 2LL + MOD) % MOD;

    printf("%lld\n", ans);
}