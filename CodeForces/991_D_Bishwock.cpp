#include <bits/stdc++.h>
using namespace std;

int n;
char s[2][200];
int memo[200][2][2];

int dp(int pos, int u1, int d1) {
  int &ret = memo[pos][u1][d1];
  if (ret == -1) {
    if (pos == n) {
      ret = 0;
    } else {
      int u0 = s[0][pos] == 'X'? 1 : 0;
      int d0 = s[1][pos] == 'X'? 1 : 0;
      ret = dp(pos+1, u0, d0);
      if (u0 == 0 && d0 == 0) {
        if (u1 == 0) ret = max(ret, 1+dp(pos+1, 1, 1));
        if (d1 == 0) ret = max(ret, 1+dp(pos+1, 1, 1));
      }
      if (u1 == 0 && d1 == 0) {
        if (u0 == 0) ret = max(ret, 1+dp(pos+1, 1, d0));
        if (d0 == 0) ret = max(ret, 1+dp(pos+1, u0, 1));
      }
    }
  }
  return ret;
}

int main() {
  memset(memo, -1, sizeof memo);
  scanf("%s", s[0]);
  scanf("%s", s[1]);
  n = strlen(s[0]);
  printf("%d\n", dp(0, 1, 1));
}