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

vector<pair<int,pair<int,int> > > edge;
int parent[1005];

void initUFDS() { for (int i=0; i<1005; i++) { parent[i] = i; } }
int findParent(int x) {
  if (parent[x] == x) return x;
  int p = findParent(parent[x]);
  parent[x] = p;
  return p;
}

void exec() {
  int n,m,p;
  int a,b,c;
  initUFDS();

  scanf("%d%d%d",&p,&n,&m);
  for (int i=0; i<m; i++) {
    scanf("%d%d%d",&a,&b,&c);
    edge.pb(mp(c, mp(a, b)));
  }
  sort(edge.begin(), edge.end());
  int ans = 0;
  int taken = 0;

  for (int i=0; taken < n-1; i++) {
    int p1 = findParent(edge[i].se.fi);
    int p2 = findParent(edge[i].se.se);
    if (p1 != p2) {
      parent[p1] = p2;
      ans += edge[i].fi;
      taken++;
    }
  }

  printf("%d\n", p * ans);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    exec();
  }
}
