#include <cstdio>
#include <climits>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
long long dp[100005][3];
long long arr[100005][3];

long long ngedp(int row, int col) {
  long long &ret = dp[row][col];
  if (ret == -1) {
    if (row == n-1) {
      if (col == 0) {
        ret = arr[row][col] + ngedp(row, col+1);
      } else if (col == 1) {
        ret = arr[row][col];
      } else {
        ret = LLONG_MAX;
      }
    } else {
      long long kiri_bawah   = LLONG_MAX;
      long long tengah_bawah = ngedp(row+1, col);
      long long kanan_bawah  = LLONG_MAX;
      long long kanan        = LLONG_MAX;

      if (col > 0) { kiri_bawah  = ngedp(row+1, col-1); }
      if (col < 2) {
        kanan_bawah = ngedp(row+1, col+1);
        kanan       = ngedp(row, col+1);
      }

      ret = arr[row][col] + min(min(kiri_bawah, tengah_bawah), min(kanan_bawah, kanan));
    }

  }
  return ret;
}

int main() {
  int t = 1;
  scanf("%d",&n);
  while (n > 0) {
    memset(dp, -1, sizeof dp);
    for (int i=0; i<n; i++) {
      scanf("%lld%lld%lld",&arr[i][0],&arr[i][1],&arr[i][2]);
    }

    printf("%d. %lld\n", t++, ngedp(0,1));

    scanf("%d",&n);
  }
}