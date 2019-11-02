#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

long long dp[1000005];

int main() {
    int n, a, b;
    scanf("%d", &n);

    dp[0] = 1LL;
    for (long long i = 1LL; i < 1000005; i++) {
        long long j = 1LL;
        long long k = 2LL;
        dp[i] = 0LL;
        while (i >= j) {
            dp[i] += dp[i - j];
            dp[i] %= MOD;
            j += k;
            k <<= 1;
        }
    }
    for (int i = 1; i < 1000005; i++) {
        dp[i] *= 2LL;
        dp[i] %= MOD;
        dp[i] += dp[i - 1];
        dp[i] %= MOD;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a, &b);
        long long ans = dp[b];
        if (a > 0) ans -= dp[a - 1];
        ans = (ans + MOD) % MOD;
        printf("%lld\n", ans);
    }
}