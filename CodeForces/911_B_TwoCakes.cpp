#include <cstdio>
#define max(a,b) ((a > b)? (a) : (b))
#define min(a,b) ((a < b)? (a) : (b))
using namespace std;

int n,a,b;

int main() {
  scanf("%d%d%d",&n,&a,&b);
  int ans = 0;
  for (int i=1; i<=n-1; i++) {
    ans = max(ans, min(a/i, b/(n-i)));
  }
  printf("%d\n", ans);
}