#include<bits/stdc++.h>
using namespace std;

int main() {
  int n = 500;
  printf("%d\n", n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      // if (i > 4) {
      //   printf("10000");
      // }
      if (i % 2 == 0) {
        printf("1");
      } else {
        printf("1");
      }
      if (j != n - 1) printf(" ");
    }
    printf("\n");
  }
}
