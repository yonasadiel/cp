#include <cstdio>
#include <algorithm>
#include <utility>
#include <cstring>
#define piii pair<int,pair<int,int> >
#define fi first
#define se second.first
#define th second.second
using namespace std;

int n,m;
piii arr[200005];
int bisa[400005];

int main() {
  memset(bisa, 0, sizeof bisa);

  scanf("%d%d",&n,&m);
  for (int i=0; i<m; i++) {
    scanf("%d%d",&arr[i].se, &arr[i].th);
    arr[i].se--; arr[i].th--;
    arr[i].fi = abs(arr[i].se - arr[i].th);
  }

  sort(arr, arr+m);

  for (int i=0; i<m; i++) {
    int ctr = arr[i].se + arr[i].th;
    if (ctr&1) {
      if (bisa[ctr]+1 == (abs(arr[i].se*2-ctr)+1)/2) {
        bisa[ctr]++;
      }
    } else {
      if (bisa[ctr]+1 == abs(arr[i].se*2-ctr)/2) {
        bisa[ctr]++;
      }
    }
  }

  int ret = bisa[0];
  for (int i=0; i<2*n-1; i++) {
    if (i&1) ret = max(ret, bisa[i]*2);
    else ret = max(ret, bisa[i]*2+1);
  }
  printf("%d\n", ret);
}