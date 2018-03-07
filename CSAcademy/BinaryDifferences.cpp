#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int a[100005];

int main() {
  scanf("%d",&n);
  for (int i=0; i<n; i++) {
    scanf("%d",&a[i]);
  }

  int c = 0;
  int hi = 0, lo = 0;
  int ans1 = 0;
  for (int i=0; i<n; i++) {
    if (a[i] == 0) {
      c++;
      if (c > hi) {
        hi = c;
        ans1 = max(ans1, hi-lo);
      }
    } else {
      c--;
      if (c < lo) {
        lo = c;
        hi = c;
      }
    }
  }

  c=0;
  hi = 0; lo = 0;
  int ans2 = 0;
  for (int i=0; i<n; i++) {
    if (a[i] == 0) {
      c++;
      if (c > hi) {
        hi = c;
        lo = c;
      }
    } else {
      c--;
      if (c < lo) {
        lo = c;
        ans2 = min(ans2, lo-hi);
      }
    }
  }

  printf("%d\n", ans1-ans2+1);
}