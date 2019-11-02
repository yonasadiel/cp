#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

long long n, m;

long long fastpow(long long a, long long b) {
    long long ans = 1LL;
    for (int i = 0; i < 63; i++) {
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
    scanf("%lld%lld", &n, &m);
    long long t = (fastpow(2, m) - 1 + MOD) % MOD;
    printf("%lld\n", fastpow(t, n));
}