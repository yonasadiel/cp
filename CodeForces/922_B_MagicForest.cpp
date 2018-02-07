#include <cstdio>
#include <algorithm>
#define MAXN 2500
using namespace std;

bool isTriangle(int a, int b, int c) {
  int ma = max(a, max(b,c));
  int mi = min(a, min(b,c));
  int mid = a+b+c-ma-mi;
  return (mi + mid > ma);
}

int main() {
  int n, x=0;
  scanf("%d",&n);
  
  for (int i=1; i<=n; i++) {
    for (int j=i+1; j<=n; j++) {
      if ((i^j) <= n && isTriangle(i, j, i^j)) {
        //printf("%d %d %d\n", i, j, i^j);
        x++;
      }
    }
  }
  if (x%3 != 0) return -1;
  printf("%d\n", x/3);
}