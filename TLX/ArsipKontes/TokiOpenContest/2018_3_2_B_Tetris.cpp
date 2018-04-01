#include <cstdio>
#include <cstring>
using namespace std;

int dp[205][205][205];

int play(int n, int a, int b) {
  int &ret = dp[n][a][b];
  if (ret == -1) {
    if (n == 0) {
      if (a == 0 && b == 0) {
        ret = 1;
      } else {
        ret = 0;
      }
    } else {
      ret = 0;
      if (ret == 0 && a >= 2          ) ret = play(n-1, a-2, b  );
      if (ret == 0 &&           b >= 2) ret = play(n-1, a  , b-2);
      if (ret == 0 && a >= 2 && b >= 1) ret = play(n-1, a-2, b-1);
      if (ret == 0 && a >= 1 && b >= 2) ret = play(n-1, a-1, b-2);
    }
    //for (int i=0; i<n; i++) printf(" "); printf("%d %d %d => %d\n", n, a, b, ret);
  }
  return ret;
}

void bt(int n, int a, int b) {
  if (n == 0) return;
  if (a >= 2           && play(n-1, a-2, b  ) == 1) { printf("SS" ); bt(n-1, a-2, b  ); return; }
  if (          b >= 2 && play(n-1, a  , b-2) == 1) { printf("RR" ); bt(n-1, a,   b-2); return; }
  if (a >= 2 && b >= 1 && play(n-1, a-2, b-1) == 1) { printf("SRS"); bt(n-1, a-2, b-1); return; }
  if (a >= 1 && b >= 2 && play(n-1, a-1, b-2) == 1) { printf("RSR"); bt(n-1, a-1, b-2); return; }
}

int main() {
  memset(dp, -1, sizeof dp);
  int n,a,b;
  scanf("%d%d%d",&n,&a,&b);
  if (play(n,a,b) == 1) {
    bt(n,a,b);
    printf("\n");
  } else {
    printf("TIDAK MUNGKIN\n");
  }
}