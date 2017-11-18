#include <cstdio>
using namespace std;

int n,m,x,y;

bool valid(int a) {
  if (a > n) return false;
  long long al = a;
  long long nl = n;
  long long ml = m;
  long long xl = x;
  long long yl = y;
  ml += yl * (nl - al);
  return (ml >= al * xl);
}

int main() {
  scanf("%d%d%d%d",&n,&m,&x,&y);

  int lo = 0;
  int hi = n;
  while (lo <= hi) {
    int mi = (lo+hi)/2;
    bool v1 = valid(mi);
    bool v2 = valid(mi+1);

    if (v1 && !v2) {
      lo = mi;
      hi = mi;
      break;
    } else if (v2) {
      lo = mi+1;
    } else {
      hi = mi-1;
    }
  }

  printf("%d\n", lo);
}