#include <cstdio>
#include <utility>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define pdiii pair<pair<double, int> ,pair<int,int> >
#define fi first
#define se second
using namespace std;

int n,m;
int a,b;
int p[200];
double cx[200];
double cy[200];
int par[200];
int mark[200];
priority_queue<pdiii> edge;

double dista(int i, int j) {
  return 4 * (abs(cx[i] - cx[j]) + abs(cy[i] - cy[j]));
}

double distb(int i, int j) {
  return 6 * sqrt((cx[i] - cx[j])*(cx[i] - cx[j]) + (cy[i] - cy[j])*(cy[i] - cy[j]));
}

double distc(int i, int j) {
  return 9 * max(abs(cx[i] - cx[j]), abs(cy[i] - cy[j]));
}

int findParent(int x) {
  if (par[x] == x) return x;
  int y = findParent(par[x]);
  par[x] = y;
  return y;
}

int main() {
  scanf("%d%d",&n,&m);
  for (int i=0; i<n; i++) {
    scanf("%lf%lf%d", &cx[i], &cy[i], &p[i]);
  }
  for (int i=0; i<m; i++) {
    scanf("%d%d", &a, &b); a--; b--;
    edge.push(mp(mp(-dista(a,b), 0), mp(a, b)));
    edge.push(mp(mp(-distb(a,b), 1), mp(a, b)));
    edge.push(mp(mp(-distc(a,b), 2), mp(a, b)));
  }

  for (int i=0; i<n; i++) {
    par[i] = i;
    mark[i] = -1;
  }
  int taken = 0;
  double ans = 0;
  while (taken < n-1) {
    pdiii cur = edge.top(); edge.pop();
    //printf("%.3lf %d %d %d ", cur.fi.fi, cur.fi.se, cur.se.fi, cur.se.se);
    if (mark[cur.se.fi] >= 0 && mark[cur.se.fi] != cur.fi.se) {
      mark[cur.se.fi] = -2;
      edge.push(mp(mp(cur.fi.fi + p[cur.se.fi], cur.fi.se), cur.se));
      //printf("a\n");
    } else if (mark[cur.se.se] >= 0 && mark[cur.se.se] != cur.fi.se) {
      mark[cur.se.se] = -2;
      edge.push(mp(mp(cur.fi.fi + p[cur.se.se], cur.fi.se), cur.se));
      //printf("b\n");
    } else {
      int pa = findParent(cur.se.fi);
      int pb = findParent(cur.se.se);
      if (pa != pb) {
        par[pa] = pb;
        taken++;
        ans += cur.fi.fi;
        if (mark[cur.se.fi] == -1) mark[cur.se.fi] = cur.fi.se;
        if (mark[cur.se.se] == -1) mark[cur.se.se] = cur.fi.se;
        //printf("c\n");
      }
    }

  }

  printf("%.8lf\n", -ans);
}