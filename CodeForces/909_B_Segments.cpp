#include <cstdio>
using namespace std;

int n;

int main() {
  scanf("%d",&n);

  int m = n/2, ans = 0;
  for (int i=1; i<=m; i++) {
    ans += i;
  }
  ans *= 2;
  if (n&1) {
    ans += n/2+1;
  }
  printf("%d\n", ans);
}