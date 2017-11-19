#include <cstdio>
#define M 1000000007
using namespace std;

long long pangkat(long long a, long long b) {
  if (b == 0) return 1;
  long long t = pangkat(a, b/2)%M;
  t *= t; t %= M;
  if (b&1) return (t*a)%M;
  return t;
}

int main() {
  long long n,m,ans,k;
  scanf("%I64d%I64d%I64d",&n,&m,&k);
  if (k == -1 && (n+m)%2 == 1) {
    printf("0\n");
    return 0;
  }
  n--; m--;

  printf("%I64d\n", pangkat(pangkat(2, n)%M, m) % M);
  return 0;
}