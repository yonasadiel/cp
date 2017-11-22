#include <cstdio>
#include <cmath>
using namespace std;

int n,k;
int arr[105];
int cnt = 0;

int main() {
  scanf("%d%d",&n,&k);
  for (int i=0; i<n; i++) {
    scanf("%d",&arr[i]);
  }

  for (int i=0; i<n; i++) {
    bool beda = true;
    for (int j=0; j<n; j++) {
      if (i != j) if (abs(arr[i] - arr[j]) <= k) beda = false;
    }
    if (beda) cnt++;
  }
  printf("%d\n", cnt);
}