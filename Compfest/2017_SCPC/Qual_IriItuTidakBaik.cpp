#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int arr[100005];

int main() {
  int t;
  scanf("%d",&t);
  while (t--) {
    int n,k;
    scanf("%d%d",&n,&k);
    for (int i=0; i<n; i++) {
      scanf("%d",&arr[i]);
    }
    sort(arr, arr+n);
    int mint = arr[n-1] - arr[0];
    for (int i=0; i+n-k-1<n; i++) {
      mint = min(mint, arr[i+n-k-1] - arr[i]);
      //cout<<i+n-k-1<<" "<<i<<endl;
    }
    printf("%d\n", mint);
  }
}