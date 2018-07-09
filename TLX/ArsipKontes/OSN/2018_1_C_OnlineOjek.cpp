#include <bits/stdc++.h>
#define MAXN 105
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;

char subsoal[10];
int v, e;
int a, b;
ll cd, cp, md, mp;
vector<pair<ll, int> > adj[MAXN];
int x, y, q;
ll k;
ll dist[MAXN];

int main() {
  for (int i=0; i<MAXN; i++) {
    dist[i] = 1;
  }

  scanf("%s", subsoal);
  scanf("%d%d", &v, &e);
  scanf("%lld%lld", &cd, &md);
  scanf("%lld%lld", &cp, &mp);
  scanf("%d%d", &a, &b);
  for (int i=0; i<e; i++) {
    scanf("%d%d%lld%d", &x, &y, &k, &q);

    ll cost = ((k+mp-1)/mp) * cp;
    if (q == 0 || k <= md) cost = min(cost, cd * k);

    adj[x].pb(make_pair(-cost, y));
    adj[y].pb(make_pair(-cost, x));
  }

  priority_queue<pair<ll, int> > pq;
  pq.push(make_pair(0, a));
  while (!pq.empty()) {
    pair<ll, int> cur = pq.top(); pq.pop();

    if (dist[cur.se] == 1) {
      dist[cur.se] = cur.fi;
      //printf("%d dist %lld\n", cur.se, cur.fi);
      for (pair<ll, int> path : adj[cur.se]) {
        ll newdist = path.fi + dist[cur.se];
        if (dist[path.se] == 1 || dist[path.se] > newdist) {
          pq.push(make_pair(newdist, path.se));
        }
      }
    }
  }

  //for (int i=1; i<=10; i++)
  printf("%lld\n", -dist[b]);
}