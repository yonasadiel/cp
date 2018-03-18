#include <cstdio>
#include <algorithm>
using namespace std;

long long n;

long long genapkan(long long x) {
  long long ans = 1000000000000000000;
  long long pow = 1;

  while (x > 0) {
    if ((x%2) == 1) {
      long long naik = (x+1)*pow;
      long long turun = (x-1)*pow + 88888888888888888%pow;
      ans = min(ans,
        min(
          naik - n + genapkan(naik),
          n - turun + genapkan(turun)
        )
      );
    }
    x/=10;
    pow *= 10;
  }
  if (ans == 1000000000000000000) return 0;
  return ans;
}

void exec(int tc) {
  scanf("%lld",&n);
  printf("Case #%d: %lld\n", tc, genapkan(n));
}

int main() {
  int t;
  scanf("%d",&t);
  for (int tc=1; tc<=t; tc++) {
    exec(tc);
  }
}