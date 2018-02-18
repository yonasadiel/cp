#include <cstdio>
#include <assert.h>
#include <cmath>
#define ll long long
using namespace std;

int main() {
  int t; scanf("%d",&t);
  while (t--) {
    ll x, m=-1;
    scanf("%I64d",&x);
    if (x == 0) { printf("1 1\n"); continue; }
    for (ll i=sqrt(x); i*i-(i/2)*(i/2) <= x; i++) {
      if (i*i == x) continue;
      for (ll j = i/sqrt(i*i-x), k=0; k<5; k++, j++) {
        if (i*i-(i/j)*(i/j) == x) {
          printf("%I64d ", i);
          m = j;
        }
        if (m != -1) break;
      }
      if (m != -1) break;
    }
    assert(m>=-1);
    printf("%I64d\n", m);
  }
}