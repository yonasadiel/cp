#include <cstdio>
#define min(a,b) ((a<b)? (a):(b))
using namespace std;

int n,m;
int arr[100005];

int main() {
  m = 2000000000;

  scanf("%d",&n);
  for (int i=0; i<n; i++) {
    scanf("%d",&arr[i]);
    m = min(arr[i],m);
  }

  int l = -10000000;
  int ans = 20000000;
  for (int i=0; i<n; i++) {
    if (arr[i] == m) {
      ans = min(ans, i-l);
      l = i;
    }
  }

  printf("%d\n", ans);
}