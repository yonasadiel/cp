#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

long long dp[1000005];

int main() {
    int n, b;
    scanf("%d", &n);

    dp[0] = 1LL;
    for (long long i = 1LL; i < 100005; i++) {
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

    for (int i = 0; i < n; i++) {
        scanf("%d", &b);
        if (b == 0) printf("1\n");
        else printf("%lld\n", (2 * dp[b]) % MOD);
    }
}