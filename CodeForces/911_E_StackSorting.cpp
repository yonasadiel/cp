#include <cstdio>
#include <stack>
#include <cstring>
using namespace std;

int n, k, a[200005];
bool ada[200005];

int main() {
  memset(ada, false, sizeof ada);

  scanf("%d%d", &n,&k);
  for (int i = 0; i < k; i++) {
    scanf("%d", &a[i]);
    ada[a[i]] = true;
  }

  int last = 0;
  for (int i=1; i<=n+1; i++) {
    if (i == n+1 || ada[i]) {
      if (last != i-1) {
        for (int j=i-1; j>=last+1; j--) {
          a[k++] = j;
        }
      }
      last = i;
    }
  }

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
  if (bisa) {
    for (int i=0; i<k; i++) {
      printf("%d", a[i]);
      if (i == k-1) printf("\n"); else printf(" ");
    }
  } else {
    printf("-1\n");
  }
}