#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, k;
int a[500005], b[500005];

void solve(int tc) {
  int ai, bi;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) { scanf("%d", &a[i]); if (a[i] == 1) ai = i; }
  for (int i = 0; i < n; i++) { scanf("%d", &b[i]); if (b[i] == 1) bi = i; }

  bool bisa = (ai == bi && k != 1) || (ai != bi && k > 0);
  if (n == 2 && !(ai == bi ^ k%2 != 0)) { bisa = false; }
  for (int i = ai, j = bi, l = 0; l < n; l++) {
    if (a[i] != b[j]) {
      bisa = false;
    }
    i = (i+1) % n;
    j = (j+1) % n;
  }

  printf("Case #%d: ", tc);
  if (!bisa) printf("NO\n");
  else printf("YES\n");
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) solve(i);
}
