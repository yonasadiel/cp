#include <cstdio>
#include <queue>
#include <utility>
#include <cstring>
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
using namespace std;

int n,m,q,p;
char pet[255][255];
long long res[255][255];
long long sudah[255][255];
queue<pii> qu;

int di[] = {0,1,0,-1};
int dj[] = {1,0,-1,0};

bool valid (pii a) {
  return a.fi >= 0 && a.se >= 0 && a.fi < n && a.se < m && pet[a.fi][a.se] != '*';
}

int main() {
  memset(res, 0, sizeof res);

  scanf("%d%d%d%d\n",&n,&m,&q,&p);
  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      scanf("%c",&pet[i][j]);
    }
    scanf("\n");
  }

  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      if (pet[i][j] != '*' && pet[i][j] != '.') {
        memset(sudah, 0, sizeof sudah);
        qu.push(mp(i,j));
        sudah[i][j] = q * (pet[i][j] - 'A' + 1);

        while(!qu.empty()) {
          pii cur = qu.front();
          qu.pop();
          res[cur.fi][cur.se] += sudah[cur.fi][cur.se];

          if (sudah[cur.fi][cur.se] > 0) {
            for (int k=0; k<4; k++) {
              pii ne;
              ne.fi = cur.fi + di[k];
              ne.se = cur.se + dj[k];

              if (valid(ne) && sudah[ne.fi][ne.se] == 0) {
                sudah[ne.fi][ne.se] = sudah[cur.fi][cur.se] / 2;
                qu.push(ne);
              }
            }
          }
        }
      }
    }
  }

  int cnt = 0;
  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      if (res[i][j] > p) {
        cnt++;
      }
    }
  }
  printf("%d\n", cnt);
}