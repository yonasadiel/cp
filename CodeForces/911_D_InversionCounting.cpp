#include <cstdio>
#include <vector>
#define ll long long
using namespace std;

int n,m;
int arr[5000];
int l,r;
ll inv;

int main() {
  scanf("%d",&n);
  for (int i=1; i<=n; i++) {
    scanf("%d",&arr[i]);
  }

  for (int i=1; i<=n; i++) {
    for (int j=i+1; j<=n; j++) {
      if (arr[j] < arr[i]) inv++;
    }
  }

  bool odd = inv % 2 == 1;

  scanf("%d",&m);
  while (m--) {
    scanf("%d%d",&l,&r);

    if ((r-l+1)%4 == 2 || (r-l+1)%4 == 3) {
      odd = !odd;
    }

    if (odd) { printf("odd\n"); }
    else { printf("even\n"); }
  }
}