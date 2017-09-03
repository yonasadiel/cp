#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
  int n,a,b;
  int xx[105], yy[105];

  scanf("%d%d%d",&n,&a,&b);
  for (int i=0; i<n; i++) {
    scanf("%d%d",&xx[i],&yy[i]);
  }

  int ret = 0;
  for (int i=0; i<n; i++) {
    for (int j=i+1; j<n; j++) {
      bool bisa = false;
      if (xx[i] <= a && xx[j] <= a && yy[i]+yy[j] <= b) { bisa = true; }
      if (xx[i] <= a && yy[j] <= a && yy[i]+xx[j] <= b) { bisa = true; }
      if (yy[i] <= a && xx[j] <= a && xx[i]+yy[j] <= b) { bisa = true; }
      if (yy[i] <= a && yy[j] <= a && xx[i]+xx[j] <= b) { bisa = true; }
      if (xx[i] <= b && xx[j] <= b && yy[i]+yy[j] <= a) { bisa = true; }
      if (xx[i] <= b && yy[j] <= b && yy[i]+xx[j] <= a) { bisa = true; }
      if (yy[i] <= b && xx[j] <= b && xx[i]+yy[j] <= a) { bisa = true; }
      if (yy[i] <= b && yy[j] <= b && xx[i]+xx[j] <= a) { bisa = true; }
      if (bisa) { ret = max(ret, xx[i]*yy[i] + xx[j]*yy[j]); }
    }
  }

  printf("%d\n", ret);
}