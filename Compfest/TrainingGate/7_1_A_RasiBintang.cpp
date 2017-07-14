#include <cstdio>
#include <cmath>
using namespace std;

int main() {
  int n;
  long long xm, ym, xp, yp, xk, yk;

  scanf("%d",&n);
  for (int i=0; i<n; i++) {
    scanf("%lld%lld%lld%lld%lld%lld",&xm,&ym,&xp,&yp,&xk,&yk);

    long long kiri = yk * (xp - xm);
    long long kanan = (yp - ym) * (xk - xm) + ym * (xp - xm);

    if (kiri == kanan) {
      printf("Case #%d: rasi ular\n", i+1);
    } else if (kiri > kanan) {
      printf("Case #%d: rasi kucing\n", i+1);
    } else {
      printf("Case #%d: rasi anjing\n", i+1);
    }
    
  }
}