#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n;

bool guess(ll x) {
  if (x == 0) return false;
  ll nn = n;
  ll v = 0;
  ll p = 0;
  while (nn > 0) {
    ll vv = min(x, nn);
    v += vv;
    nn -= vv;

    p += nn/10;
    nn -= nn/10;
  }
  return v >= p;
}

int main() {
  scanf("%I64d", &n);
  ll lo = 1;
  ll hi = n;
  while (lo < hi) {
    ll mi = (lo + hi) / 2;
    bool gmi = guess(mi);
    if (gmi && !guess(mi-1)) {
      lo = mi;
      hi = mi;
    } else if (gmi) {
      hi = mi-1;
    } else {
      lo = mi+1;
    }
  }
  printf("%I64d\n", lo);
}

