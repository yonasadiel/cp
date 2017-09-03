#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int p, d, i;

double pangkat(double basis, long long atas) {
  if (atas == 0) return 1.00;
  if (atas == 1) return basis;
  double le = pangkat(basis, atas/2);
  if (atas&1) return le*le*basis;
  else        return le*le;
}

bool valid(long long bulan) {
  return p*pangkat((100+i)*1.0/100, bulan) >= d*1.0;
}

void main_per_case(int kasus){
  scanf("%d%d%d",&p, &d, &i);
  if (p >= d) {
    printf("Case #%d: %d\n", kasus, 0);
    return;
  } else {
    long long lo = 1;long long hi = 1000000000;
    while (lo <= hi) {
    //printf("%d %d\n", lo, hi);  
      long long mi = (lo+hi)/2;
      if (valid(mi) && !valid(mi-1)) {
        printf("Case #%d: %d\n", kasus, mi);
        return;
      } else if(valid(mi)) {
        hi = mi-1;
      } else {
        lo = mi+1;
      }
    }
    while(1);
  }
}

int main(){
  int t;
  scanf("%d",&t);
  for (int t_i=1; t_i<=t; t_i++) {
    main_per_case(t_i);
  }
}