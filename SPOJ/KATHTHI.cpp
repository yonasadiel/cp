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

const bool debug = false;

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

int r,c;
char pet[1005][1005];
int dist[1005][1005];
const int DIRECTION = 4;
int dr[] = {0, 1, 0, -1};
int dc[] = {-1, 0, 1, 0};
#define INF 100000000

bool valid(pii p) {
  return p.fi >= 0 && p.se >= 0 && p.fi < r && p.se < c;
}

void exec() {
  scanf("%d%d\n",&r,&c);
  for (int i=0; i<r; i++) {
    for (int j=0; j<c; j++) {
      scanf("%c",&pet[i][j]);
      dist[i][j] = INF;
    }
    scanf("\n");
  }

  deque<pii> dq;
  dq.push_front(mp(0,0));
  dist[0][0] = 0;
  while (!dq.empty()) {
    pii cur = dq.front(); dq.pop_front();
    DEBUG dump(cur);
    for (int i=0; i<DIRECTION; i++) {
      pii next = mp(cur.fi + dr[i], cur.se + dc[i]);
      int new_dist;
      if (pet[cur.fi][cur.se] != pet[next.fi][next.se]) { new_dist = dist[cur.fi][cur.se] + 1; }
      else { new_dist = dist[cur.fi][cur.se]; }
      if (valid(next) && dist[next.fi][next.se] > new_dist) {
        if (pet[cur.fi][cur.se] != pet[next.fi][next.se]) {
          dist[next.fi][next.se] = new_dist;
          dq.push_back(next);
          DEBUG dump(next);
        } else {
          dist[next.fi][next.se] = new_dist;
          dq.push_front(next);
          DEBUG dump(next);
        }
      }
    }
    DEBUG dumpln();
  }
  printf("%d\n", dist[r-1][c-1]);
}

int main() {
  int t;
  scanf("%d",&t);
  while (t--) exec();
}
