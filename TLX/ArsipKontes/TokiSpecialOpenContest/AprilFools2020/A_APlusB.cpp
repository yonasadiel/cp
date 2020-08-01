#include <bits/stdc++.h>
using namespace std;

int f[3000];

int main() {
  f[1] = 1;
  f[2] = 2;
  for (int i = 3; i <= 3000; i += 1) {
    f[i] = (f[i - 1] * i) % 1009;
  }
  int a, b;
  scanf("%d%d", &a, &b);
  if (b > 2020) {
    printf("%d\n", a % 1009);
  } else {
    printf("%d\n", (a + f[b]) % 1009);
  }
}
