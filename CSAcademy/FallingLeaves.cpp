#include <cstdio>
#define ll long long
using namespace std;

ll t,c,n;
ll xi, yi, si;
int ans[1005];

int main() {
  scanf("%lld%lld%lld",&t,&c,&n);
  for (int i=0; i<n; i++) {
    scanf("%lld%lld%lld", &xi, &yi, &si);
    if ((yi * c - xi * si) % (si * c) == 0) {
      ll t = (yi * c - xi * si) / (si * c);
      if (t >= 0 && t <= 1000) {
        ans[t]++;
      }
    }
  }
  for (int i=0; i<t; i++) {
    printf("%d\n", ans[i]);
  }
}