#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;

int n,m;
ll arr[100], brr[100];

int main() {
  scanf("%d%d",&n,&m);
  for (int i=0; i<n; i++) {
    scanf("%I64d",&arr[i]);
  }
  for (int i=0; i<m; i++) {
    scanf("%I64d",&brr[i]);
  }
  int take = 0;
  ll maks = arr[0]*brr[0];
  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      if (arr[i]*brr[j] > maks) {
        maks = arr[i]*brr[j];
        take = i;
      }
    }
  }
  maks = (take == 0)? arr[1]*brr[0] : arr[0]*brr[0];
  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      if (i != take) {
        if (arr[i]*brr[j] > maks) {
          maks = arr[i]*brr[j];
        }
      }
    }
  }
  printf("%I64d\n", maks);


}