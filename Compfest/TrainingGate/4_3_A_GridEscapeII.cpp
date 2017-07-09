#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int r,c;
char petak[1005][1005];
int dist[1005][1005];
queue<pair<int,int> > q;

int dr[] = {0,1,0,-1};
int dc[] = {1,0,-1,0};

bool valid(int rc, int cc) {
  return (rc < r && rc >= 0 && cc < c && cc >= 0);
}

int main() {
  memset(dist, -1, sizeof dist);

  scanf("%d%d",&r,&c);
  for (int i=0; i<r; i++) {
    scanf("%c",&petak[i][0]);
    for (int j=0; j<c; j++) {
      scanf("%c",&petak[i][j]);
    }
  }

  dist[0][0] = 0;
  q.push(make_pair(0,0));

  while (!q.empty()) {
    int rn = q.front().first;
    int cn = q.front().second;
    q.pop();

    for (int i=0; i<4; i++) {
      int rm = rn + dr[i];
      int cm = cn + dc[i];

      if (valid(rm,cm) && dist[rm][cm] == -1 && petak[rm][cm] != '#') {
        dist[rm][cm] = dist[rn][cn] + 1;
        q.push(make_pair(rm,cm));
      }
    }
  }

  printf("%d\n",dist[r-1][c-1]);
}