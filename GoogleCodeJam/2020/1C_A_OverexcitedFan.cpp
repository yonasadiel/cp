#include <bits/stdc++.h>
using namespace std;

void solve(int tc) {
  int r, c, nr, nc, len, ans = -1;
  char s[1005];
  scanf("%d %d %[^\n]", &c, &r, s);
  nr = r, nc = c;
  len = strlen(s);
  // printf("*%d %d %s*\n", r, c, s);

  if ((nr + nc) == 0) {
    ans = 0;
  }
  for (int i = 0; i < len; i++) {
    if (s[i] == 'N') nr++;
    else if (s[i] == 'S') nr--;
    else if (s[i] == 'W') nc--;
    else if (s[i] == 'E') nc++;
    if (ans == -1 && (abs(nr) + abs(nc)) <= i + 1) {
      ans = i + 1;
    }
  }
  if (ans != -1) {
    printf("Case #%d: %d\n", tc, ans);
  } else {
    printf("Case #%d: IMPOSSIBLE\n", tc);
  }
}

int main() {
  int t;
  scanf("%d", &t);
  for (int i = 1; i <= t; i++) solve(i);
}
