#include <cstdio>
using namespace std;

int main() {
  int n;
  int arr[105];

  scanf("%d", &n);
  for (int i = 0; i < n; ++i) { scanf("%d",&arr[i]); }

  if (n&1 && arr[0]&1 && arr[n-1]&1) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
}