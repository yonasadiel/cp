#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <cmath>
#define INF 1e20
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;

int v,e;
map<string, int> m;
string s1, s2;
double f;
vector<pair<pair<int,int>, double> > edge;
double dist[50][50];

void exec(int tc) {
  edge.clear();
  for (int i=0; i<v; i++) {
    cin >> s1;
    m[s1] = i;
  }
  scanf("%d",&e);
  for (int i=0; i<e; i++) {
    cin >> s1 >> f >> s2;
    edge.pb(mp(mp(m[s2], m[s1]), -log(f)));
  }

  for (int i=0; i<v; i++)
    for (int j=0; j<v; j++)
      dist[i][j] = INF;

  for (int src=0; src<v; src++) {
    dist[src][src] = 0;
    for (int i=0; i<v; i++) {
      for (int j=0; j<e; j++) {
        if (dist[src][edge[j].fi.se] > dist[src][edge[j].fi.fi] + edge[j].se) {
          dist[src][edge[j].fi.se] = dist[src][edge[j].fi.fi] + edge[j].se;
        }
      }
    }
  }

  bool neg = false;
  for (int i=0; i<v; i++) {
    if (dist[i][i] < 0) {
      neg = true;
    }
  }

  if (neg) {
    printf("Case %d: Yes\n", tc);
  } else {
    printf("Case %d: No\n", tc);
  }
}

int main() {
  int i=1;
  while (1) {
    scanf("%d", &v);
    if (v > 0) {
      exec(i);
      i++;
    } else {
      break;
    }
  }
}