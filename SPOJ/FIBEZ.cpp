#include <cstdio>
#define MAXN 500005
#define MOD 100000007
using namespace std;

int fibo[MAXN];

int main() {
  fibo[0] = 1;
  fibo[1] = 1;
  for (int i=2; i<MAXN; i++) {
    fibo[i] = (fibo[i-1] + fibo[i-2]) % MOD;
  }

  int n,k;
  scanf("%d",&k);
  while (k--) {
    scanf("%d",&n);
    printf("%d\n", fibo[n-1]);
  }
}