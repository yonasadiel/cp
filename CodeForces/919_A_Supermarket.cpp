#include <cstdio>
#include <algorithm>
using namespace std;

double a[5005];

int main() {
  int n,m;
  double c,b;

  scanf("%d%d",&n,&m);
  for (int i=0; i<n; i++) {
    scanf("%lf%lf",&c,&b);
    a[i] = (double) c/b;
  }

  sort(a, a+n);
  printf("%.9lf\n", a[0]*m);
}