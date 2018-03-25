#include <cstdio>
#include <cmath>
using namespace std;

int main() {
  int x, ans;

  for (int i=0; i<5; i++) {
    for (int j=0; j<5; j++) {
      scanf("%d",&x);
      if (x == 1) ans = abs(i-2)+abs(j-2);
    }
  }

  printf("%d\n", ans);
}