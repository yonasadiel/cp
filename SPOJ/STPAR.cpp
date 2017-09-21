#include <bits/stdc++.h>

using namespace std;

int n,a[100000];
int main() {
  while (1) {
    scanf("%d", &n);
    if (n == 0)
      break;
    for (int i = 0; i < n; i++)
      scanf("%d", a + i);

    int last_kanan = 0;
    stack<int> yang_bawah;
    for (int i = 0; i < n; i++) {
      while (!yang_bawah.empty() && yang_bawah.top() == last_kanan + 1)
        yang_bawah.pop(), last_kanan++;
      if (a[i] == last_kanan + 1)
        last_kanan = a[i];
      else
        yang_bawah.push(a[i]);
      while (!yang_bawah.empty() && yang_bawah.top() == last_kanan + 1)
        yang_bawah.pop(), last_kanan++;
    }
    bool bisa = 1;
    while (!yang_bawah.empty()) {
      int x = yang_bawah.top(); yang_bawah.pop();
      if (x != last_kanan + 1)
        bisa = 0;
      else
        last_kanan++;
    }
    printf("%s\n", bisa ? "yes" : "no");
  }
  return 0;
}