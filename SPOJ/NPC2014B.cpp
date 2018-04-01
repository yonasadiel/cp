#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;

int n;
ll arr[5005];

ll solve(int l, int r, ll last) {
  if (l >= r) return 0;
  if (l+1 == r) return 1;
  int min_i = l;
  for (int i=l; i<r; i++) {
    if (arr[i] < arr[min_i]) min_i = i;
  }

  ll ans = arr[min_i] - last;
  int last_i = l, i;
  for (i=last_i; i<r; i++) {
    if (arr[i] != arr[min_i]) {
      int j;
      for (j=i+1; arr[j] != arr[min_i] && j<r; j++);
      ans += solve(i, j, arr[min_i]);
      i=j;
    }
  }
  //printf("%d %d %lld %lld\n", l, r, last, ans);
  return min(ans, (ll)r-l);
}

int main() {
  scanf("%d",&n);
  for (int i=0; i<n; i++) {
    scanf("%lld",&arr[i]);
  }
  printf("%lld\n", solve(0, n, 0));
}