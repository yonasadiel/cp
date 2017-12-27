#include <cstdio>
#include <cstring>
#define ll int
#define MOD 1000000007
#define rundp(a, b) ((dp[a][b] == -1)? (rundp_exec(a,b)) : (dp[a][b]))
#define rundp2(a, b) ((dp2[a][b] == -1)? (rundp2_exec(a,b)) : (dp2[a][b]))
using namespace std;

int n;
char arr[5005];
ll dp[5005][5005];
ll dp2[5005][5005];

ll rundp_exec(int pos, int ind);
ll rundp2_exec(int pos, int ind);

int main() {
  scanf("%d\n",&n);

  memset(dp , -1, sizeof dp );
  memset(dp2, -1, sizeof dp2);
  for (int i=0; i<n; i++) {
    scanf("%c\n", &arr[i]);
  }

  for (int pos=n; pos >=0; pos--) {
    for (int ind=0; ind <=n; ind++) {
      ll &ret2 = dp2[pos][ind];
      if (ind == 1) ret2 = dp[pos+1][ind];
      else if (ind == 0) ret2 = 0;
      else ret2 = (dp[pos+1][ind] + dp2[pos][ind-1]) % MOD;
    }

    for (int ind=0; ind <= n; ind++) {
      ll &ret = dp[pos][ind];
      if (pos == n) ret = 1;
      else if (ind == n) ret = 0;
      else {
        if (pos == 0) {
          if (arr[pos] == 'f') {
            ret = dp[pos+1][ind+1] % MOD;
          } else {
            ret = dp[pos+1][ind] % MOD;
          }
        } else {
          if (arr[pos] == 'f') {
            if (arr[pos-1] == 's') {
              ret = dp2[pos][ind+1] % MOD;
            } else {
              ret = dp[pos+1][ind+1] % MOD;
            }        
          } else {
            if (arr[pos-1] == 's') {
              ret = dp2[pos][ind] % MOD;
              ret += dp[pos+1][0] % MOD;
              ret %= MOD;
            } else {
              ret = dp[pos+1][ind] % MOD;
            }
          }
        }
      }
    }
  }

/*
  for (int i=0; i<=n; i++) {
    for (int j=0; j<=n; j++) {
      printf("%d ", dp[i][j]);
    } printf("\n");
  }
*/
  printf("%d\n", dp[0][0] % MOD);
}