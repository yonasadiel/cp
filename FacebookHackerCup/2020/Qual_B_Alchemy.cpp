#include <bits/stdc++.h>
using namespace std;

void solve(int tc) {
  int n;
  char* s;
  scanf("%d", &n);
  s = (char*) malloc((n + 20) * sizeof (char));
  scanf(" %s", s);
  int cnt[] = {0, 0};
  for (int i = 0; i < n; i++) {
    cnt[s[i] - 'A']++;
  }
  printf("Case #%d: %c\n", tc, abs(cnt[0] - cnt[1]) == 1 ? 'Y' : 'N');
  free(s);
}

int main() {
  int t;
  scanf("%d", &t);
  for (int i = 1; i <= t; i++) {
    solve(i);
  }
}
