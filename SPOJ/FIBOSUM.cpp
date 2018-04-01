#include <cstdio>
#include <cmath>
#include <cstring>
#define ll long long
#define MOD 1000000007
using namespace std;

#define MAX_N 3 // increase this if needed
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

ll g(int n) {
  if (n <= 0) return 0;
  if (n == 1) return 1;
  Matrix ans;
  ans.mat[0][0] = 1; ans.mat[0][1] = 1; ans.mat[0][2] = 1;
  ans.mat[1][0] = 0; ans.mat[1][1] = 1; ans.mat[1][2] = 1;
  ans.mat[2][0] = 0; ans.mat[2][1] = 1; ans.mat[2][2] = 0;
  ans = matPow(ans, n-1);
  return (ans.mat[0][0] + ans.mat[0][1]) % MOD; 
}

int main() {
  int t, n, m;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d",&n,&m);
    ll gn = g(n-1);
    ll gm = g(m);
    ll ans = (gm - gn + MOD) % MOD;
    printf("%lld\n", ans);
  }
}