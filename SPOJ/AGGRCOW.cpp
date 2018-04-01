#include <cstdio>
#include <algorithm>
using namespace std;

int n,c;
int arr[100005];

bool bisa(int x) {
  int cnt = 1;
  int last = arr[0];
  for (int i=1; i<n; i++) {
    if(arr[i] - last >= x) {
      last = arr[i];
      cnt++;
    }
  }
  return (cnt >= c);
}

void exec() {
  scanf("%d%d", &n, &c);
  for (int i=0; i<n; i++) {
    scanf("%d", &arr[i]);
  }
  sort(arr, arr+n);

  int hi = 1000000001;
  int lo = 0;
  while (lo < hi) {
    //printf("%d %d\n", lo, hi);
    int mi = (hi+lo) /2;
    bool bmi = bisa(mi);
    if (bmi && !bisa(mi+1)) {
      hi = mi;
      lo = mi;
      break;
    } else if (bmi) {
      lo = mi+1;
    } else {
      hi = mi-1;
    }
  }
  printf("%d\n", hi);
}

int main() {
  int t;
  scanf("%d",&t);
  while (t--) {
    exec();
  }
}