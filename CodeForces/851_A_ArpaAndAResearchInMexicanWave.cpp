#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
  int n, k, t, r;
  scanf("%d%d%d",&n,&k,&t);
  r = min(n, t);
  r -= max(0, t-k);
  printf("%d\n", r);
}