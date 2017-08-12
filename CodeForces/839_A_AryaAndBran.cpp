#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
  int n, k, l = 0, m;
  scanf("%d%d", &n, &k);
  for (int i=0; i<n; i++) {
    scanf("%d", &m);
    int take = min(8, l + m);
    k -= take;
    l += m - take;
    if (k <= 0) {
      printf("%d\n", i+1);
      return 0;
    }
  }
  printf("-1\n");
}