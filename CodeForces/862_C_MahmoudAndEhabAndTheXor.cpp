#include <cstdio>
#include <cmath>
using namespace std;

int main() {
  int n,x;
  scanf("%d%d",&n,&x);

  if (n == 1) {
    printf("YES\n%d\n", x);
  } else {
    if (x&1) {
      int cur = 0;
      printf("YES\n");
      for (int i=0, j=2; i<n-1; i++, j+=2) {
        printf("%d ", j);
        cur ^= j;
      }
      printf("%d\n", cur ^ x);
    } else if (x != 0) {
      if (n > 2) {
        printf("YES\n");
        int cur = 0;
        for (int i=1; i<=n-2; i++) {
          printf("%d ", i);
          cur ^= i;
        }
        printf("524288 %d\n", 524288^cur^x);
      } else {
        printf("YES\n");
        printf("1 %d\n", x^1);
      }
    } else {
      if (n > 2) {
        printf("YES\n");
        int cur = 0;
        for (int i=1,j=1; i<=n-2; j++) {
          if (cur^j) {
            printf("%d ", j);
            cur ^= j;
            i++;
          }
        }
        printf("524288 %d\n", 524288^cur);
      } else {
        printf("NO\n");
      }
    }
  }
}