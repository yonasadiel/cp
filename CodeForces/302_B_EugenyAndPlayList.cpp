#include <cstdio>
#include <algorithm>
using namespace std;

int arr[100005];

int main() {
  int n,m,a,b;

  scanf("%d%d",&n,&m);

  arr[0] = 1;
  for (int i=1; i<=n; i++) {
    scanf("%d%d",&a,&b);
    arr[i] = arr[i-1] + a*b;
  }

  while(m--) {
    scanf("%d",&a);
    printf("%d\n",(int) (upper_bound(arr, arr+1+n, a) - arr) );
  }
}