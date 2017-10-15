#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int arr[5005];

int main() {
  scanf("%d",&n);
  for (int i=0; i<n; i++) {
    scanf("%d", &arr[i]);
  }

  sort(arr, arr+n);

  int cnt = 0;
  for (int i=2; i<n; i++) {
    for (int j=1; j<i; j++) {
      int sum = arr[i]-arr[j];
      cnt  += (int) (upper_bound(arr, arr+j, sum) - lower_bound(arr, arr+j, sum));
    }
  }

  printf("%d\n", cnt);
}