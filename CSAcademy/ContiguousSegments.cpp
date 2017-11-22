#include <cstdio>
#include <utility>
#include <algorithm>
#define ll long long
#define pll pair<ll,ll>
#define fi first
#define se second
using namespace std;

int n;
pll arr[2005];

int main() {
  scanf("%d",&n);
  for (int i=0; i<n; i++) {
    scanf("%lld%lld",&arr[i].fi, &arr[i].se);
  }
  sort(arr, arr+n);

  ll ret;
  for (int i=0; i<n; i++) {
    ll last, cnt = 0;

    last = arr[i].fi;
    for (int j=i-1; j>=0; j--) {
      cnt += (last - arr[j].se);
      last -= (arr[j].se - arr[j].fi);
    }

    last = arr[i].se;
    for (int j=i+1; j<n; j++) {
      cnt += (arr[j].fi - last);
      last += (arr[j].se - arr[j].fi);
    }

    if (i == 0) {
      ret = cnt;
    } else {
      ret = min(ret, cnt);
    }
  }

  printf("%lld\n", ret);
}