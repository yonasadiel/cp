#include <cstdio>
#include <vector>
#include <utility>
#include <cstring>
#include <queue>
#include <algorithm>
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
using namespace std;

int n,k;
vector<pii> adj[100005];
int subnode[100005];
bool vis[100005];
bool bisa[100005];
int a,b,c;

int traverse(int node) {
  subnode[node] = 1;
  for (int i=0; i<adj[node].size(); i++) {
    pii next = adj[node][i];
    if (subnode[next.first] == -1) {
      subnode[node] += traverse(next.first);
      bisa[next.first] = next.second;
    }
  }
  return subnode[node];
}

bool desc_sec(pii a, pii b) {
  return subnode[a.first] > subnode[b.first];
}

int main() {
  memset(subnode, -1, sizeof subnode);
  memset(vis, false, sizeof vis);

  scanf("%d%d",&n,&k);
  for (int i=0; i<n-1; i++) {
    scanf("%d%d%d",&a,&b,&c);
    adj[a].pb(mp(b,c));
    adj[b].pb(mp(a,c));
  }

  subnode[1] = 0;
  subnode[1] = traverse(1);
  bisa[1] = false;

  priority_queue<pii> pq;
  pq.push(mp(n,1));
  int del = 0;
  int cnt = 0;
  vis[1] = true;

  for (int i=1; i<=n; i++) { sort(adj[i].begin(), adj[i].end(), desc_sec); }

  while (!pq.empty() && del < n-k) {
    pii pcur = pq.top();
    int cur = pcur.second;
    pq.pop();

    if (bisa[cur]) {
      del += subnode[cur];
      cnt++;
    } else {
      for (int i=0; i<adj[cur].size() && del < n-k; i++) {
        pii next = adj[cur][i];
        if (!vis[next.first]) {
          vis[next.first] = true;
          pq.push(mp(subnode[next.first],next.first));
        }
      }  
    }

    

  }

  if (del < n-k) {
    printf("-1\n");
  } else {
    printf("%d\n", cnt);
  }
  

}