#include <cstdio>
using namespace std;

int n;
int arr[105]; int brr[105];

int main() {
  scanf("%d",&n);
  for (int i=0; i<n; i++) {
    scanf("%d%d",&arr[i],&brr[i]);
  }

  int ans = 0;
  for (int i=0; i<n; i++) {
    int cnt = 0;
    for (int j=0; j<n; j++) {
      if (i == j) continue;
      if (arr[i] > arr[j] && brr[i] < brr[j]) {
        cnt++;
      }
    }
    if (cnt > 0) ans++;
  }

  printf("%d\n", ans);
}