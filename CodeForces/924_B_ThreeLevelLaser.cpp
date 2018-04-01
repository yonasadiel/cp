#include <cstdio>
#include <algorithm>
using namespace std;

int n,u;
int e[100005];

int main() {
  scanf("%d%d",&n,&u);
  for (int i=0; i<n; i++)
    scanf("%d",&e[i]);

  double maks = -1;
  for (int i=1; i+1<n; i++) {
    int atas = upper_bound(e,  e+n, e[i-1]+u) - e;
    atas--;
    if (atas > i) {
      maks = max(maks, (e[atas] - e[i]) * 1.0 / (e[atas] - e[i-1]));
    }
  }
  if (maks < 0) {
    printf("-1\n");
  } else {
    printf("%.11lf\n", maks);
  }
}