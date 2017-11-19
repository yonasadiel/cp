#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int m;
int arr[1005];
bool brr[1000005];

int main() {
  memset(brr, false, sizeof brr);

  scanf("%d",&m);
  for (int i=0; i<m; i++) {
    scanf("%d",&arr[i]);
    brr[arr[i]] = true;
  }

  int gcd = arr[0];
  bool bisa = true;
  for (int i=0; i<m; i++) {
    gcd = __gcd(arr[i], gcd);
  }

  if (brr[gcd]) {
    printf("%d\n", 2*m);
    for (int i=0; i<m; i++) {
      if (i == m-1) { printf("%d %d\n", gcd, arr[i]); }
      else { printf("%d %d ", gcd, arr[i]); }
    }
  } else {
    printf("-1\n");
  }
}