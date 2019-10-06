#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

int n, l, r;
ll dp[200005][3];

int main() {
    scanf("%d%d%d", &n, &l, &r);

    ll zero = (r + 0) / 3 - (l - 1 + 0) / 3;
    ll one  = (r + 2) / 3 - (l - 1 + 2) / 3;
    ll two  = (r + 1) / 3 - (l - 1 + 1) / 3;
    dp[1][0] = zero;
    dp[1][1] = one;
    dp[1][2] = two;
    for (int len=2; len<=n; len++) {
        dp[len][0] = ((dp[len-1][0] * zero) % MOD + (dp[len-1][1] * two ) % MOD + (dp[len-1][2] * one ) % MOD) % MOD;
        dp[len][1] = ((dp[len-1][0] * one ) % MOD + (dp[len-1][1] * zero) % MOD + (dp[len-1][2] * two ) % MOD) % MOD;
        dp[len][2] = ((dp[len-1][0] * two ) % MOD + (dp[len-1][1] * one ) % MOD + (dp[len-1][2] * zero) % MOD) % MOD;
    }
    printf("%lld\n", dp[n][0]);
}