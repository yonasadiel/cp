/**
 * ParadePanjang
 * TL: 1s
 * Print longest path in Directed Acyclic Graph.
 * Needed Toposort to optimze
 * TLE on bruteforce traversal (BFS/DFS with checking more max path)
 * Constraints:
 *   1 <= N <= 100 000
 *   1 <= M <= 100 000
 */

#include <cstdio>
#include <vector>
#include <stack>
#include <utility>
#include <algorithm>
#include <cstring>
using namespace std;

int n,m;
int a,b;
long long c;
vector<pair<long long,int> > chld[100005];
vector<pair<long long,int> > prnt[100005];
stack<int> st;
int cntprnt[100005];
int tkn[100005];
long long dist[100005];
vector<int> hasil_topo;

void topo() {
  for (int i=1; i<=n; i++) {
    if (cntprnt[i] == 0) { st.push(i); }
  }

  while(!st.empty()) {
    int cur = st.top();
    st.pop();

    hasil_topo.push_back(cur);
    tkn[cur] = true;

    for (int i=0; i<chld[cur].size(); i++) {
      int next = chld[cur][i].second;
      cntprnt[next]--;

      if (!tkn[next] && cntprnt[next] == 0) {
        st.push(next);
      }
    }
  }
}

int main() {
  memset(dist, -1, sizeof dist);
  memset(cntprnt,  0, sizeof cntprnt);
  memset(tkn, false, sizeof tkn);

  scanf("%d%d",&n,&m);
  for (int i=0; i<m; i++) {
    scanf("%d%d%lld",&a,&b,&c);
    chld[a].push_back(make_pair(c,b));
    prnt[b].push_back(make_pair(c,a));
    cntprnt[b]++;
  }

  topo();

  dist[1] = 0;

  for (int i=0; i<n; i++) {
    int cur = hasil_topo[i];
    // printf("DEBUG HASIL TOPO : %d isinya %d\n",i,cur);
    if (cur != 1) dist[cur] = -1;
    for (int j=0; j<prnt[cur].size(); j++) {
      dist[cur] = max(dist[cur], prnt[cur][j].first + dist[prnt[cur][j].second]);
      // printf("DEBUG CARI JALAN TERJAUH : jalan ke %d dari %d jadinya %d\n", j, prnt[cur][j].second, dist[i]);
    }
  }

  printf("%lld\n",dist[n]);
}