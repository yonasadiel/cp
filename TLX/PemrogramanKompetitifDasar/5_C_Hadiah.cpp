#include <cstdio>
#define ll long long
using namespace std;

ll n,a,b,c;

ll pangkat(ll base, ll top) {
  ll ans = 1;
  ll ttop = 1;
  for (int i=0; i<63; i++) {
    if (top & ttop) {
      ans *= base;
      ans %= n;
    }
    base *= base;
    base %= n;
    ttop <<= 1;
  }
  return ans;
}

int main() {
  scanf("%lld%lld%lld%lld", &a,&b,&c,&n);
  ll ans = a;
  for (ll i=0; i<c; i++) ans = pangkat(ans, b);
  if (ans < 0) return 1;
  printf("%lld\n", ans+1);
}