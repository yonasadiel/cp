#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;

ll n;
ll s[1005], d[1005];

int main() {
  scanf("%I64d",&n);
  for (int i=0; i<n; i++) {
    scanf("%I64d%I64d",&s[i],&d[i]);
  }

  ll t = 0;
  for (int i=0; i<n; i++) {
    ll k;
    if (s[i] > t) {
      k = 0;
    } else if (s[i] == t) {
      k = 1;
    } else {
      k = (t+1 - s[i] + d[i]-1) / d[i];
    }
    t = k*d[i] + s[i];
  }
  printf("%I64d\n", t);
}