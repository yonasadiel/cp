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
int n,m;
int s,f;
int a,b,c;
vector<pii> adj[100005];
vector<int> dist[100005];
#define INF 1000000000
#define K 2

void exec() {
  scanf("%d%d",&n,&m);
  s=0; f=n-1;
  for (int i=0; i<n; i++) {
    dist[i].clear();
    adj[i].clear();
  }
  for (int i=0; i<m; i++) {
    scanf("%d%d%d", &a, &b, &c); a--; b--;
    adj[a].pb(mp(-c,b));
    adj[b].pb(mp(-c,a));
  }
  priority_queue<pii> pq;
  pq.push(mp(0, s));
  dist[s].pb(0);
  while (!pq.empty()) {
    pii cur = pq.top(); pq.pop();
    //dumpln(cur);
    if (dist[cur.se].size() == 0 || dist[cur.se].back() != cur.fi) {
      dist[cur.se].pb(cur.fi);
    }
    for (int i=0; i<adj[cur.se].size(); i++) {
      pii next = adj[cur.se][i];
      //dump(' '); dumpln(next);
      if (dist[next.se].size() < K) {
        int newdist = cur.fi + next.fi;
        pq.push(mp(newdist, next.se));
      }
    }
  }
  if (dist[f].size() < K) {
    printf("NONE\n");
  } else {
    printf("%d\n", -dist[f][K-1]);
  }
}

int main() {
  exec();
}
