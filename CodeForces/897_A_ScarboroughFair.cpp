#include <cstdio>
using namespace std;

long long k,p;

long long zycith(long long i) {
  long long j = i;
  while (j > 0) {
    i *= 10;
    i += j%10;
    j /= 10;
  }
  return i;
}

int main() {
  long long ans=0;

  scanf("%d%d",&k,&p);
  for (long long i=1; i<=k; i++) {
    ans += zycith(i);
    ans %= p;
  }

  printf("%I64d\n",ans);
}