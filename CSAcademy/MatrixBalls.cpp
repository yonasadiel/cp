#include <cstdio>
#include <cstring>
using namespace std;

int n,m;
int a[505][505];
int ar[300005];
int ac[300005];
int c [300005];
int v[505][505];
int dr[] = {0, 1, -1, 0, 1, -1, 1, -1};
int dc[] = {1, 0, 0, -1, -1, -1, 1, 1};


int main() {
  memset(ar, -1, sizeof ar);
  memset(ac, -1, sizeof ac);

  scanf("%d%d",&n,&m);
  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      scanf("%d",&a[i][j]);
      ar[a[i][j]] = i;
      ac[a[i][j]] = j;
    }
  }

  memset(v, -1, sizeof v);
  for (int i=1; i<=300005; i++) {
    if (ar[i] == -1) continue;
    if (v[ar[i]][ac[i]] == -1) {
      v[ar[i]][ac[i]] = i;
    }
    for (int j=0; j<8; j++) {
      int nr = ar[i] + dr[j];
      int nc = ac[i] + dc[j];
      if (nr < n && nc < m && nr >= 0 && nc >= 0 && v[nr][nc] == -1) {
        v[nr][nc] = v[ar[i]][ac[i]];
      }
    }
  }

  memset(c, 0, sizeof c);
  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      c[v[i][j]]++;
    }
  }
  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      printf("%d%c", c[a[i][j]], (j==m-1)?'\n':' ');
    }
  }


}
