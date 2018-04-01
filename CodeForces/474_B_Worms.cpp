#include <cstdio>
#include <algorithm>
using namespace std;

int n,m,x;
int a[100005];
int b[100005];

int main() {
  scanf("%d",&n);
  for (int i=0; i<n; i++) {
    scanf("%d", &a[i]);
    if (i == 0) b[i] = a[i];
    else b[i] = a[i] + b[i-1];
  }
  scanf("%d", &m);
  for (int i=0; i<m; i++) {
    scanf("%d",&x);
    int lo = lower_bound(b, b+n, x) - b;
    printf("%d\n", lo+1);
  }
}