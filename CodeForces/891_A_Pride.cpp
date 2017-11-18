#include <cstdio>
#include <algorithm>
using namespace std;

int n,m;
int a[2005];

int main() {
  scanf("%d",&n);
  m=n;
  int adasatu = 0;
  for (int i=0; i<n; i++) {
    scanf("%d",&a[i]);
    if (a[i] == 1) adasatu++;
  }

  if (adasatu > 0) {
    printf("%d\n", n-adasatu);
    return 0;
  }

  while (n > 0) {
    for (int i=0; i<n; i++) {
      a[i] = __gcd(a[i], a[i+1]);
      if (a[i] == 1) adasatu = true;
    }
    n--;

    if (adasatu) {
      printf("%d\n",m-n-1+m);
      break;
    }
  }

  if (!adasatu) {
    printf("-1\n");
  }
}