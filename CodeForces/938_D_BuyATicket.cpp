#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#define ll long long
#define pii pair<ll, int>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;

int n,m;
vector<pii> adj[200005];
ll price[200005];
priority_queue<pii, vector<pii>, greater<pii> > pq;

int main() {
  scanf("%d%d",&n,&m);
  ll c;
  for (int i=0, a, b; i<m; i++) {
    scanf("%d%d%I64d",&a,&b,&c);
    a--; b--; c*=2;
    adj[a].pb(mp(c, b));
    adj[b].pb(mp(c, a));
  }
  for (int i=0; i<n; i++) {
    scanf("%I64d",price+i);
  }

  for (int i=0; i<n; i++) {
    pq.push(mp(price[i], i));

  }

  while (!pq.empty()) {
    pii top = pq.top(); pq.pop();

    if (price[top.se] != top.fi) { continue; }
    for (int j=0; j<adj[top.se].size(); j++) {
      pii ne = adj[top.se][j];
      if (price[ne.se] > price[top.se] + ne.fi) {
        price[ne.se] = price[top.se] + ne.fi;
        pq.push(mp(price[ne.se], ne.se));
      }
    }
  }

  for (int i=0; i<n; i++) {
    printf("%I64d%c",price[i], (i==n-1)?'\n':' ');
  }
}