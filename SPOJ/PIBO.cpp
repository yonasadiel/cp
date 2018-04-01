#include <cstdio>
#include <cmath>
#include <cstring>
#define ll long long
#define MOD 1111111111
using namespace std;

#define MAX_N 120 // increase this if needed
struct Matrix { ll mat[MAX_N][MAX_N]; }; // to let us return a 2D array
Matrix matMul(Matrix a, Matrix b) { // O(n^3), but O(1) as n = 2
  Matrix ans; int i, j, k;
  for (i = 0; i < MAX_N; i++)
    for (j = 0; j < MAX_N; j++)
      for (ans.mat[i][j] = k = 0; k < MAX_N; k++) {
        ans.mat[i][j] += ((a.mat[i][k] % MOD) * (b.mat[k][j] % MOD)) % MOD;
        ans.mat[i][j] %= MOD; // modulo arithmetic is used here
      }
  return ans;
}

Matrix matPow(Matrix base, int p) { // O(n^3 log p), but O(log p) as n = 2
  Matrix ans; int i, j;
  for (i = 0; i < MAX_N; i++)
    for (j = 0; j < MAX_N; j++)
      ans.mat[i][j] = (i == j); // prepare identity matrix
  while (p) { // iterative version of Divide & Conquer exponentiation
    if (p & 1) // check if p is odd (the last bit is on)
      ans = matMul(ans, base); // update ans
    base = matMul(base, base); // square the base
    p >>= 1; // divide p by 2
  }
  return ans;
}

int main() {
  int n, d;
  ll c[105];
  scanf("%d%d",&n,&d);
  if (n < 2) {
    printf("1\n");
    return 0;
  }
  for (int i=0; i<=d; i++) {
    scanf("%lld",&c[i]);
  }
  Matrix ans;
  for (int i=0; i<=d+2; i++) {
    for (int j=0; j<=d+2; j++) {
      if (i == 0) {
        if (j < 2) ans.mat[i][j] = 1;
        else ans.mat[i][j] = c[j-2];
      } else if (i == 1) {
        ans.mat[i][j] = (j == 0);
      } else if (i == 2) {
        ans.mat[i][j] = (j == 2);
      } else {
        if (j < 2) ans.mat[i][j] = 0;
        else ans.mat[i][j] = (ans.mat[i-1][j] + ans.mat[i-1][j-1]) % MOD;
      }
    }
  }
  ans = matPow(ans, n-1);
  ll res = 0;
  ll coef = 1;
  for (int j=0; j<=d+2; j++) {
    res += (coef * ans.mat[0][j]) % MOD;
    res %= MOD;
    if (j >= 2) coef *= 2;
    coef %= MOD;  
  }
  printf("%lld\n", res);

}