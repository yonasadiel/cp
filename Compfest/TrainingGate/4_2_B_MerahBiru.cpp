/**
 * Merah Biru
 * TL: 1s
 * Check whether a graph can be a bipartite graph
 * Constraints:
 *   1 <= N <= 100 000
 *   1 <= M <= 100 000
 */

#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int n,m;
int a,b;
vector<int> adj[100005];
int color[100005];

bool coloring(int node, int color_now) {
  bool ret = true;
  color[node] = color_now;

  for (int i=0; i<adj[node].size(); i++) {
    int next = adj[node][i];
    if (color[next] == -1) {
      ret = ret && coloring(next, 1-color_now);
    } else if (color[next] == color_now) {
      return false;
    }
  }

  return ret;
}

int main() {
  scanf("%d%d",&n,&m);
  for (int i=0; i<m; i++) {
    scanf("%d%d",&a,&b);
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  memset(color, -1, sizeof color);

  bool bisa = true;
  for (int i=1; i<=n; i++) {
    if (color[i] == -1) bisa = bisa && coloring(i,0);
  }

  if (bisa) {
    printf("YA\n");
  } else {
    printf("TIDAK\n");
  }
}