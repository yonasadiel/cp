#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
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
#define pdd pair<double,double>
#define DEBUG if (debug)
using namespace std;

const bool debug = true;

void dump(int x) { fprintf(stderr, "%d", x); }
void dump(char x) { fprintf(stderr, "%c", x); }
void dump(char* x) { fprintf(stderr, "%s", x); }
void dump(ll x) { fprintf(stderr, "%I64d", x); }
void dump(float x) { fprintf(stderr, "%.5f", x); }
void dump(double x) { fprintf(stderr, "%.5lf", x); }
void dump(string x) { cerr << x; }
template<class T> void dump(T* x, int n) { dump('['); for (int i=0; i<n; i++) { if (i>0) dump(','); dump(x[i]); } dump(']'); }
template<class T> void dump(vector<T> x) { dump('<'); for (int i=0; i<x.size(); i++) { if (i>0) dump(','); dump(x[i]); } dump('>'); }
template<class T1, class T2> void dump(pair<T1, T2> x) { dump('('); dump(x.fi); dump(','); dump(x.se); dump(')'); }

void dumpln() { fprintf(stderr, "\n"); }
template<class T> void dumpln(T* x, int n) { dump(x, n); dump('\n'); }
template<class T> void dumpln(T x) { dump(x); dumpln(); }

#define MAXN 100
#define INF 100000

int n,m;
int a,b,c;
vector<pair<int,pii> > edge;
vector<pair<int,pii> > not_mst;
vector<pii> adj[MAXN+5];
int parent[MAXN+5];

int findParent(int x) {
  if (x == parent[x]) return x;
  int p = findParent(parent[x]);
  parent[x] = p;
  return p;
}

void exec() {
  edge.clear();
  not_mst.clear();
  for (int i=0; i<MAXN; i++) { parent[i] = i; }
  for (int i=0; i<MAXN; i++) { adj[i].clear(); }

  scanf("%d%d",&n,&m);
  for (int i=0; i<m; i++) {
    scanf("%d%d%d",&a,&b,&c); a--; b--;
    edge.pb(mp(c, mp(a,b)));
  }
  sort(edge.begin(), edge.end());
  int short1=0;
  for (int i=0; i<edge.size(); i++) {
    int p1 = findParent(edge[i].se.fi);
    int p2 = findParent(edge[i].se.se);
    if (p1 != p2) {
      parent[p1] = p2;
      short1 += edge[i].fi;
      adj[edge[i].se.fi].pb(mp(edge[i].fi, edge[i].se.se));
      adj[edge[i].se.se].pb(mp(edge[i].fi, edge[i].se.fi));
    } else {
      not_mst.pb(edge[i]);
    }
  }

  int max_path[MAXN+5][MAXN+5];
  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      max_path[i][j] = -1;
    }
    queue<int> q;
    q.push(i);
    max_path[i][i] = 0;

    while (!q.empty()) {
      int cur = q.front(); q.pop();
      for (int j=0; j<adj[cur].size(); j++) {
        pii next = adj[cur][j];
        if (max_path[i][next.se] == -1) {
          max_path[i][next.se] = max(max_path[i][cur], next.fi);
          q.push(next.se);
        }
      }
    }
  }

  int short2=INF;
  for (int i=0; i<not_mst.size(); i++) {
    short2 = min(short2, not_mst[i].fi - max_path[not_mst[i].se.fi][not_mst[i].se.se]);
  }
  short2 += short1;

  printf("%d %d\n", short1, short2);

}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) { exec(); }
}
