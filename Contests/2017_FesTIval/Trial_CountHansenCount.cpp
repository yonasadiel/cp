#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int t,a,b,c,arr[105];

int main() {
  scanf("%d",&t);
  for (int t_i=1; t_i<=t; t_i++) {
    scanf("%d%d",&a,&b);

    int d = 0;
    for (int i = 0; i<a; i++) { scanf("%d",&c); d += c; }

    c = ceil(1.0*b/d);

    printf("Case #%d: %d\n", t_i, c);
  }


  return 0;
};