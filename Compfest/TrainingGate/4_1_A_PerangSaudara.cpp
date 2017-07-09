#include <cstdio>
#include <cstring>
using namespace std;

bool adj[1005][1005];

int main() {
  memset(adj, false, sizeof adj);
  int n,m,q;
  int a,b;
  scanf("%d%d",&n,&m);
  for (int i=0; i<m; i++) {
    scanf("%d%d",&a,&b);
    adj[a][b] = true;
    adj[b][a] = true;
  }
  scanf("%d",&q);
  for (int i=0; i<q; i++) {
    scanf("%d%d",&a,&b);
    int cnt = 0;
    for (int i=1; i<=n; i++) {
      if (adj[a][i] && adj[b][i]) { cnt++; }
    }
    printf("%d\n",cnt);
  }
}