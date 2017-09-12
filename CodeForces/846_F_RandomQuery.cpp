#include <cstdio>
#include <cstring>
#define ll long long
#define MAXN 1000000
using namespace std;

ll n,x;
ll ans = 0;
ll pre[MAXN+5];
ll last[MAXN+5];

void isi() {
  memset(pre, 0, sizeof pre);
  for (ll i=1; i<=MAXN; i++) {
    pre[i] = i + pre[i-1];
  }
  for (ll i=1; i<=MAXN; i++) {
    pre[i] += pre[i-1];
  }
  for (ll i=1; i<=MAXN; i++) {
    pre[i] = pre[i] * 2 - i;
  }
}

int main() {
  memset(last, -1, sizeof last);
  isi();
  scanf("%I64d", &n);
  ans = pre[n];

  for (ll i=1; i<=n; i++) {
    scanf("%I64d",&x);
    if (last[x] != -1) {
      ans -= 2 * (n - i + 1) * (last[x]);
    }
    last[x] = i;
  }

  printf("%.6lf\n", (double) ans / n / n);
}