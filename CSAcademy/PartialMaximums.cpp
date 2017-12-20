#include <cstdio>
#include <algorithm>
using namespace std;

int n,x;
int arr[200005];
int maks[200005];

int main() {
  scanf("%d",&n);
  for (int i=0;i<n; i++) {
    scanf("%d",&arr[i]);
    if (i == 0) maks[i] = arr[i];
    else maks[i] = max(maks[i-1], arr[i]);
  }
  int cnt = 0;
  for (int i=0; i<n; i++) {
    if (i == 0 || maks[i] != maks[i-1]) {
      cnt++;
    }
  }
  int ans = 0;
  for (int i=0; i<n; i++) {
    if (i == 0 || maks[i] != maks[i-1]) {
      int plus = 0;
      int maks_t = (i > 0)? maks[i-1] : -1;
      for (int j=i+1; j<n && maks[j] == maks[j-1]; j++) {
        if (arr[j] > maks_t) {
          plus++;
          maks_t = arr[j];
        }
      }
      ans = max(ans, cnt+plus-1);
    }
  }
  
  printf("%d\n", ans);
}