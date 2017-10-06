#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
  int n, arr[100];
  scanf("%d",&n);
  n *= 2;

  for(int i=0; i<n; i++) {
    scanf("%d",&arr[i]);
  }
  sort(arr, arr+n);

  int ret = 500000;
  for (int i1=0; i1<n; i1++) {
    for (int i2=i1+1; i2<n; i2++) {
      int sum = 0;
      for (int i=0, j=0; i<n; i++) {
        if (i == i1 || i == i2) { continue; }
        if (j&1) sum += arr[i];
        else     sum -= arr[i];
        j++;
      }
      ret = min(sum,ret);
    }
  }

  printf("%d\n", ret);
}