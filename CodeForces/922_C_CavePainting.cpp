#include <cstdio>
#include <cmath>
#include <algorithm>
#define ll long long
using namespace std;

int main() {

  ll n,k;

  scanf("%I64d%I64d",&n,&k);
  if (k == 1 || (n == 1 && k == 2)) {
    printf("Yes\n");
    return 0;
  }
  if (k >= n) {
    printf("No\n");
    return 0;
  }
  for (ll i=1; i<=min(k,50LL); i++) {
    if (n%i != i-1) {
      //printf("%I64d ", i);
      printf("No\n");
      return 0;
    }
  }
  printf("Yes\n");
  return 0;
}