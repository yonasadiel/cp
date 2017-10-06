#include <cstdio>
using namespace std;

long long ret = 0;

int main() {
  long long n,a;
  scanf("%lld",&n);
  for (int i=0; i<2*n; i++) {
    scanf("%lld",&a);
    ret += (a*n);
  }
  printf("%lld\n", ret);
}