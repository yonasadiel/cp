#include <cstdio>
#include <utility>
#include <algorithm>
#define ll long long
#define pii pair<ll,ll>
#define fi first
#define se second
using namespace std;

int n;
pii arr[100005];

bool comp(pii a, pii b) {
  if (a.fi == b.fi) return a.se < b.se;
  return a.fi < b.fi;
}

ll luas(ll kiri, ll kanan) {
  if ((kanan-kiri) %2 == 0) {
    ll x= (kanan-kiri)/2+1;
    return x*x;
  } else {
    ll x= (kanan-kiri)/2+1;
    return x*(x+1);
  }
}

int main() {
  scanf("%d", &n);
  for (int i=0; i<n; i++) {
    scanf("%lld%lld", &arr[i].se, &arr[i].fi);
    arr[i].fi = arr[i].fi - arr[i].se + 1;
    arr[i].se = arr[i].fi + 2 * arr[i].se - 2;
  }
  sort(arr, arr+n, comp);
  
  ll last = arr[0].se;
  ll ans = luas(arr[0].fi, arr[0].se);
  //printf("%lld %lld  %lld\n", arr[0].fi, arr[0].se, ans);
  for (int i=1; i<n; i++) {
    if (arr[i].se <= last) continue;
    ans += luas(arr[i].fi, arr[i].se);
    if (arr[i].fi <= last) {
      ans -= luas(arr[i].fi, last);
    }
    last = max(last, arr[i].se);
    //printf("%lld %lld  %lld\n", arr[i].fi, arr[i].se, ans);
  }
  printf("%lld\n", ans);
}