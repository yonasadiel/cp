#include <cstdio>
#define ll long long
#define MOD 10000007
using namespace std;

ll pangkat(ll a, ll b) {
  if (b == 0) return 1;
  if (b == 1) return a;
  ll c = pangkat(a, b/2) % MOD;
  if (b&1) return ((c * c) % MOD) * a % MOD;
  return (c * c) % MOD;
}

int main() {
  ll n, m;
  scanf("%lld%lld", &n, &m);
  while (n>0 || m>0) {
    ll ans = 0;
    ans += (pangkat(n,m) % MOD) + 2 * (pangkat(n-1,m) % MOD);
    ans %= MOD;
    ans += (pangkat(n,n) % MOD) + 2 * (pangkat(n-1,n-1) % MOD);
    ans %= MOD;
    printf("%lld\n", ans);
    scanf("%lld%lld",&n, &m);
  }
}