#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

void main_per_case(int kasus){
  int n,m,kapt,serd;
  scanf("%d%d",&n,&m);

  kapt = 0;
  serd = 1;
  n--;
  while(n>0) {
    serd -= 1;
    kapt += 1;
    int nserd = min(n, m);
    n -= nserd;
    serd += nserd;
  }
  printf("Case #%d: %d %d\n", kasus, kapt, serd);
}

int main(){
  int t;
  scanf("%d",&t);
  for (int t_i=1; t_i<=t; t_i++) {
    main_per_case(t_i);
  }
}