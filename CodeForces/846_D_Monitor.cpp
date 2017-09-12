#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,m,k,q;
int t[505][505];
int mn[505][505][2];
int mx[505][505][2];

int main() {
  memset(t, -1, sizeof t);
  scanf("%d%d%d%d",&n,&m,&k,&q);
  for (int i=0; i<q; i++) {
    int xx,yy,tt;
    scanf("%d%d%d",&xx,&yy,&tt);
    t[xx][yy] = tt;
  }

  int ans = -1;
  for (int sz=1; sz <=k; sz++) {
    for (int i=sz; i<=n; i++) {
      for (int j=sz; j<=m; j++) {
        if (sz == 1) {
          mn[i][j][1] = t[i][j];
          mx[i][j][1] = t[i][j];
        }
        else {
          mx[i][j][sz%2] = max(max(mx[i-1][j][(sz-1)%2], mx[i][j-1][(sz-1)%2]), max(mx[i-1][j-1][(sz-1)%2], mx[i][j][(sz-1)%2]));
          mn[i][j][sz%2] = min(min(mn[i-1][j][(sz-1)%2], mn[i][j-1][(sz-1)%2]), min(mn[i-1][j-1][(sz-1)%2], mn[i][j][(sz-1)%2]));
        }
        if (sz == k && mn[i][j][sz%2] != -1) {
          if (ans == -1) { ans = mx[i][j][sz%2]; }
          else { ans = min(ans, mx[i][j][sz%2]); }
        }
      }
    }
  }
  printf("%d\n", ans);
}