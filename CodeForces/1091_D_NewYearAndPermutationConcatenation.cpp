#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

int n;

long long fpow(long long base, long long to) {
    long long ans = 1;
    for (int i=0; i<32; i++) {
        if (to & (1 << i)) {
            ans *= base;
            ans %= MOD;
        }
        base *= base;
        base %= MOD;
    }
    return ans;
}

long long inv_mod(long long b) {
    return fpow(b, MOD-2);
}

int main() {
    scanf("%d", &n);
    long long fact_n = 1LL;
    for (long long i = 1; i <= n; i++) { fact_n *= i; fact_n %= MOD; }
    long long ans = 0;
    long long k = 1;
    for (long long i=1; i <= n; i++) {
        // ans += n! - (n! / i!)
        long long ad = 0;
        k *= i;
        k %= MOD;
        ad += fact_n;
        ad %= MOD;

        long long temp = fact_n;
        temp *= inv_mod(k);
        temp %= MOD;

        ad += MOD - temp;
        ad %= MOD;
        // printf("i = %d, k = %lld, %lld\n", i, k, ad);
        ans += ad;
        ans %= MOD;
    }
    ans++;
    ans %= MOD;
    printf("%lld\n", ans);
}