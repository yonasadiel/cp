#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

char subsoal[10];
int n;
int k;
int a[50005];
ll fpb[505][505];

int main() {
  scanf("%s", subsoal);
  scanf("%d%d", &n, &k);
  for (int i=0; i<n; i++) {
    scanf("%d", &a[i]);
  }
  ll ans = 0;
  if (k == 1 && n <= 10000) {
    for (int i=0; i<n; i++) {
      ll temp = a[i];
      for (int j=i; j<n; j++) {
        temp = __gcd(temp, (ll) a[j]);
        ans += temp;
        ans %= MOD;
      }
    }
  } else if (k == 2) {
    for (int i=0; i<n; i++) {
      fpb[i][i] = a[i];
      for (int j=i+1; j<n; j++) {
        fpb[i][j] = __gcd(fpb[i][j-1], (ll) a[j]);
      }
    }
    for (int i=0; i<n; i++) {
      for (int j=i; j<n; j++) {
        ll kiri = ((i) * (i+1) / 2) % MOD;
        ll kanan = ((n-1-j) * (n-j) / 2) % MOD;
        ans += (fpb[i][j] * (kiri + kanan) % MOD) % MOD;
        ans %= MOD;
      }
    }
  } else if (subsoal[8] == '8') {
    //
  } else {
    return -1;
  }
  printf("%lld\n", ans);
}