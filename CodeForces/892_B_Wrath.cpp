#include <cstdio>
#include <algorithm>
using namespace std;

int l[1000005];

int main() {
  int n;
  scanf("%d",&n);
  for (int i=0; i<n; i++) {
    scanf("%d",&l[i]);
  }

  int last = 0;
  int count = 0;
  for (int i=n-1; i>=0; i--) {
    if (last > 0) {
      last--;
      last = max(last, l[i]);
    } else {
      count++;
      last = l[i];
    }
  }
  printf("%d\n", count);
}