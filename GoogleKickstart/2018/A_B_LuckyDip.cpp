#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int arr[20000];
double dp[50005];

void exec(int tc) {
  int k;
  scanf("%d%d",&n,&k);
  for (int i=0; i<=k; i++) dp[i] = -1;
  for (int i=0; i<n; i++) {
    scanf("%d", &arr[i]);
  }

  for (int j=0; j<=k; j++) {
    double ans = 0;
    if (j == 0) {
      for (int i=0; i<n; i++) {
        ans += arr[i];
      }
    } else {
      for (int i=0; i<n; i++) {
        ans += max((double)arr[i], dp[j-1]);
      }
    }
    dp[j] = ans/n;
  }

  printf("Case #%d: %.8lf\n", tc, dp[k]);
}

int main() {
  int t;
  scanf("%d",&t);
  for (int tc=1; tc<=t; tc++) {
    exec(tc);
  }
}