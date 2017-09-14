#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,k;
int cnt[1005];

int main() {
  memset(cnt, 0, sizeof cnt);
  scanf("%d",&n);
  for (int i=0; i<n; i++) {
    scanf("%d",&k);
    cnt[k]++;
  }

  int cnnt = 0;
  int hi = 0;
  for (int i=0; i<1005; i++) {
    hi = max(hi, cnt[i]);
    if (cnt[i] > 0) cnnt++;
  }

  printf("%d %d\n",hi, cnnt);
}