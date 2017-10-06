#include <cstdio>
#include <cstring>
#define MOD 998244353
using namespace std;
  
long long a,b,c;
long long dpa[5005][5005];

long long ngedpa(long long pos, long long taken) {
  long long &ret = dpa[pos][taken];
  if (ret == -1) {
    if (pos == 0 || taken == 0) {
      ret = 1;
    } else {
      ret = (
        ((taken * (ngedpa(pos-1, taken-1) % MOD)) % MOD) +
        (ngedpa(pos-1, taken)) % MOD
      ) % MOD;
    }
  }
  return ret;
}

int main() {
  memset(dpa, -1, sizeof dpa);

  scanf("%I64d%I64d%I64d",&a,&b,&c);

  long long ans = 1;

  ans *= ngedpa(a, b) % MOD;
  ans %= MOD;

  // printf("%I64d\n", ans);

  ans *= ngedpa(b, c) % MOD;
  ans %= MOD;

  // printf("%I64d\n", ans);

  ans *= ngedpa(c, a) % MOD;
  ans %= MOD;

  printf("%I64d\n", ans);
}