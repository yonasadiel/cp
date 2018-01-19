#include <cstdio>
using namespace std;

bool lucky(int n) {
  return n%10 == 7 || n/10 == 7;
}

int main() {
  int x, h, m, n = 0;

  scanf("%d",&x);
  scanf("%d%d",&h,&m);

  while (!(lucky(h) || lucky(m))) {
    m -= x;
    if (m < 0) {
      m += 60;
      h--;
    }
    if (h < 0) {
      h += 24;
    }
    n++;
  }
  printf("%d\n", n);
}