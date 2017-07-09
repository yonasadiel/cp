/**
 * PulauBiner
 * TL: 1s
 * BFS 1/0 using deque
 * TLE on bruteforce traversal (BFS/DFS with checking more max path), WA on DP
 * Constraints:
 *   1 <= N <= 1000
 */

#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int n;
char petak[1005][1005];
int dist[1005][1005];
deque<pair<int,int> > q;

int dr[] = {0,1,0,-1};
int dc[] = {1,0,-1,0};

bool valid(int rc, int cc) {
  return (rc < n && rc >= 0 && cc < n && cc >= 0);
}

int main() {
  memset(dist, -1, sizeof dist);

  scanf("%d",&n);
  for (int i=0; i<n; i++) {
    scanf("%c",&petak[i][0]);
    for (int j=0; j<n; j++) {
      scanf("%c",&petak[i][j]);
    }
  }

  dist[0][0] = petak[0][0] - '0';
  q.push_back(make_pair(0,0));

  while (!q.empty()) {
    int rn = q.front().first;
    int cn = q.front().second;
    q.pop_front();

    for (int i=0; i<4; i++) {
      int rm = rn + dr[i];
      int cm = cn + dc[i];

      if (valid(rm,cm) && dist[rm][cm] == -1) {
        dist[rm][cm] = dist[rn][cn] + petak[rm][cm] - '0';
        if (petak[rm][cm] == '0') q.push_front(make_pair(rm,cm));
        if (petak[rm][cm] == '1') q.push_back (make_pair(rm,cm));
      }
    }
  }

  printf("%d\n",dist[n-1][n-1]);
}