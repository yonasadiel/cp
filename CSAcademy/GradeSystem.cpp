#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
  int n;
  int arr[105];
  
  scanf("%d",&n);
  for (int i=0; i<n; i++) {
    scanf("%d",&arr[i]);
  }
  sort(arr, arr+n);
  
  int sum = 0;
  for (int i=1; i<n-1; i++) {
    sum += arr[i];
  }
  printf("%d\n", sum/(n-2));
}