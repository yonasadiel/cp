#include <cstdio>
#include <cmath>
using namespace std;

int t(int n) {
  if (n == 1) return 1;

  return 1+t(ceil(n*1.0/2))+t(floor(n*1.0/2));
}

int main() {
  int n;
  scanf("%d",&n);
  printf("%d\n",t(n));
}