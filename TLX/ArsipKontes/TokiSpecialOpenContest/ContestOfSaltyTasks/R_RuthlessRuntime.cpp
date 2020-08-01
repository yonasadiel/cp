#include <cstdio>
#include <algorithm>

#define ll long long
#define MOD 1000000007

ll pangkat(ll base, ll to) {
  ll ans = 1LL;
  for (int i = 0; i < 64; i++) {
    if (to & (1LL << i)) {
      ans *= base;
      ans %= MOD;
    }
    base *= base;
    base %= MOD;
  }
  return ans;
}

ll g(ll n, ll m) {
    return (
      (n * n) % MOD
      - (n * m) % MOD
      + MOD + MOD
    ) % MOD;
}

ll f(ll n, ll m) {
    ll z = 0;
    while (n--)
        z = ((n + z) % MOD * (n - m + MOD) % MOD) % MOD;
    return z;
}

int main() {
    ll t, n, m;
    scanf("%lld", &t);
    while (t--) {
        scanf("%lld %lld", &n, &m);
        printf("%lld\n", f(std::min(n, m), m));
    }
    return 0;
}
