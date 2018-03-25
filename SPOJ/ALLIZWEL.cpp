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
char pet[105][105];
bool taken[105][105];
const int DIRECTION = 8;
int dr[] = {0, 1, -1, 0, 1, 1, -1, -1};
int dc[] = {1, 0, 0, -1, 1, -1, 1, -1};
const string s = "ALLIZZWELL";

bool valid(pii p) {
  return (p.fi >= 0 && p.se >= 0 && p.fi < r && p.se < c);
}

bool dfs(pii pos, int step) {
  DEBUG { for (int i=0; i<step; i++) dump(' '); dump(s[step]); dumpln(pos); }
  if (step == s.length()-1) {
    return true;
  } else {
    bool bisa = false;
    for (int i=0; i<DIRECTION; i++) {
      pii next = mp(pos.fi + dr[i], pos.se + dc[i]);
      if (valid(next) && pet[next.fi][next.se] == s[step+1] && !taken[next.fi][next.se]) {
        taken[next.fi][next.se] = true;
        bisa = bisa || dfs(next, step+1);
        taken[next.fi][next.se] = false;
      }
    }
    return bisa;
  }
}

void exec() {
  queue<pii> q;
  scanf("%d%d\n",&r,&c);
  for (int i=0; i<r; i++) {
    for (int j=0; j<c; j++) {
      scanf("%c",&pet[i][j]);
      taken[i][j] = false;
      if (pet[i][j] == 'A') q.push(mp(i,j));
    }
    scanf("\n");
  }
  DEBUG for (int i=0; i<r; i++) dumpln(pet[i], c);

  bool bisa = false;
  while (!q.empty()) {
    pii cur = q.front(); q.pop();
    taken[cur.fi][cur.se] = true;
    bisa = bisa || dfs(cur, 0);
    taken[cur.fi][cur.se] = false;
  }
  if (bisa) { printf("YES\n"); }
  else { printf("NO\n"); }
}

int main() {
  int t;
  scanf("%d",&t);
  while (t--) { exec(); }
}
