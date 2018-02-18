#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int arr[100005];

int main() {
  scanf("%d",&n);
  for (int i=0; i<n; i++) { scanf("%d",&arr[i]); }
  sort(arr, arr+n);
  int ans = 0;
  for (int i=0; i<n; i++) {
    ans = max(ans, min(arr[i] - 1, 1000000 - arr[i]));
  }
  printf("%d\n", ans);
}