#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int t,n,arr[5005],brr[5005],le;

bool desc(int a, int b) {
  return a>b;
}

int main(){
  scanf("%d",&t);
  for (int t_i=1; t_i<=t; t_i++) {
    scanf("%d",&n);

    for (int i=0; i<n; i++) { scanf("%d",&arr[i]); }
    for (int i=0; i<n; i++) { scanf("%d",&brr[i]); }
    sort(arr, arr+n, desc);

    bool bisa = true;
    le = 0;
    for (int i=0; i<n; i++) {
      le += arr[i];
      le -= brr[i];

      if (le < 0) { bisa = false; }
    }

    if (bisa) {
      printf("Case #%d: Yes he made it\n", t_i);
    } else {
      printf("Case #%d: IMPOSSIBLE\n", t_i);
    }
    
  }


  return 0;
}