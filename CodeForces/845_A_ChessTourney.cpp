#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
  int n;
  int arr[2005];
  int cnt = 0;

  scanf("%d",&n);
  for (int i=0; i<2*n; i++) {
    scanf("%d",&arr[i]);
  }
  sort(arr, arr + 2 * n);

  if (arr[n-1] == arr[n]) {
    printf("NO\n");
  } else {
    printf("YES\n");
  }
}