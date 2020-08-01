#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  int c[1005];
  memset(c, 0, sizeof c);
  scanf("%d%d", &n, &k);
  if (k == 1) {
    if (n % 2 == 1) {
      printf("First\n");
      fflush(stdout);
    } else {
      printf("Second\n");
      fflush(stdout);
    }
    for (int i = 0; i < n; i++) {
      if ((n - i) % 2 == 1) {
        for (int j = 1; j <= n; j++) {
          if (c[j] == 0) {
            printf("%d\n", j);
            fflush(stdout);
            c[j] = 1;
            break;
          }
        }
      } else {
        int x;
        scanf("%d", &x);
        c[abs(x)] = 1;
      }
    }
  }
}
