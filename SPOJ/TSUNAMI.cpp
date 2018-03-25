#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <map>
#include <set>
#define ll long long
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define DEBUG if (debug)
using namespace std;

const bool debug = true;

void dump(int x) { fprintf(stderr, "%d", x); }
void dump(char x) { fprintf(stderr, "%c", x); }
void dump(char* x) { fprintf(stderr, "%s", x); }
void dump(double x) { fprintf(stderr, "%.5lf", x); }
void dump(ll x) { fprintf(stderr, "%I64d", x); }
void dump(string x) { cerr << x; }
template<class T> void dump(T* x, int n) { dump('['); for (int i=0; i<n; i++) { if (i>0) dump(','); dump(x[i]); } dump(']'); }
template<class T> void dump(vector<T> x) { dump('<'); for (int i=0; i<x.size(); i++) { if (i>0) dump(','); dump(x[i]); } dump('>'); }
template<class T1, class T2> void dump(pair<T1, T2> x) { dump('('); dump(x.fi); dump(','); dump(x.se); dump(')'); }

void dumpln() { fprintf(stderr, "\n"); }
template<class T> void dumpln(T* x, int n) { dump(x, n); dump('\n'); }
template<class T> void dumpln(T x) { dump(x); dumpln(); }

int n;
pii node[1005];
vector<pair<double,int> > adj[1005];
int parent[1005];
bool visited[1005];
priority_queue<pair<int,pair<double, int> > > pq;

double dist(pii a, pii b) {
  return sqrt((a.fi-b.fi)*(a.fi-b.fi) + (a.se-b.se)*(a.se-b.se));
}

bool ascBySe(pii a, pii b) {
  if (a.se == b.se) return a.fi < b.fi;
  return a.se < b.se;
}

int main() {
  scanf("%d", &n);
  while (n > 0) {
    for (int i=0; i<n; i++) {
      scanf("%d%d", &node[i].fi, &node[i].se);
      adj[i].clear();
    }
    sort(node, node+n, ascBySe);

    double ans = 0;
    for (int i=0; i<n; i++) {
      for (int j=0; j<n; j++) {
        if (i != j && node[j].se >= node[i].se) {
          adj[i].pb(mp(-1 * dist(node[i], node[j]), j));
        }
      }
    }

    memset(visited, false, sizeof visited);
    int bottom = 0;
    for (int i=0; i<n && node[i].se == node[0].se; i++) {
      bottom++;
      pq.push(mp(10000,mp(0, i)));
    }

    while (!pq.empty()) {
      pair<double, int> now = pq.top().se;
      pq.pop();

      if (visited[now.se]) continue;
      //dump(now);
      visited[now.se] = true;
      ans += now.fi;
      for (int i=0; i<adj[now.se].size(); i++) {
        if (!visited[adj[now.se][i].se]) {
          pq.push(mp(-node[adj[now.se][i].se].se,adj[now.se][i]));
        }
      }
    }

    printf("%.2f\n", -1 * ans + node[bottom-1].fi - node[0].fi);

    scanf("%d", &n);
  }
  
}