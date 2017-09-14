#include <cstdio>
#include <cmath>
using namespace std;

double d,r;
int n;
double xa, ya, ra;

int main() {
  scanf("%lf%lf",&r,&d);
  scanf("%d",&n);
  int cnt = 0;
  for (int i=0; i<n; i++) {
    scanf("%lf%lf%lf", &xa, &ya, &ra);

    if (hypot(xa,ya)-ra >= r-d && hypot(xa,ya)+ra <= r && ra <= d) {
      cnt++;
    }
  }

  printf("%d\n", cnt);
}