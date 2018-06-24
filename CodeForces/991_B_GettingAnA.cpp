#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  int ar[105];
  double c = 0;
  
  scanf("%d", &n);
  for (int i=0; i<n; i++) {
    scanf("%d", &ar[i]);
    c += ar[i];
  }
  sort(ar, ar+n);

  int ans = 0;
  for (; c/n < 4.5 && ans<n; ans++) {
    c += (5 - ar[ans]);
    ar[ans] = 5;
  }
  printf("%d\n", ans);
}