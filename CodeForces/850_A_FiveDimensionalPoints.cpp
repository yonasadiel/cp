#include <cstdio>
#include <utility>
#include <vector>
#include <cmath>
#define point pair<int,pair<int,pair<int,pair<int,int> > > >
#define x1 first
#define x2 second.first
#define x3 second.second.first
#define x4 second.second.second.first
#define x5 second.second.second.second
#define mp(a,b,c,d,e) make_pair(a,make_pair(b,make_pair(c,make_pair(d,e))))
using namespace std;

point p[1005];
vector<int> ans;

double opdot(point a, point b) {
  return a.x1*b.x1 + a.x2*b.x2 + a.x3*b.x3 + a.x4*b.x4 + a.x5*b.x5;
}

int main() {
  int n;
  scanf("%d",&n);
  for (int i=0; i<n; i++) {
    scanf("%d%d%d%d%d",&p[i].x1,&p[i].x2,&p[i].x3,&p[i].x4,&p[i].x5);
  }

  for (int a=0; a<n; a++) {
    bool bener = true;

    for (int b=0; b<n && bener; b++) {
      for (int c=0; c<n && bener; c++) {
        if (b != c && a != b && a != c) {
          point ab = mp(p[a].x1-p[b].x1,p[a].x2-p[b].x2,p[a].x3-p[b].x3,p[a].x4-p[b].x4,p[a].x5-p[b].x5);
          point ac = mp(p[a].x1-p[c].x1,p[a].x2-p[c].x2,p[a].x3-p[c].x3,p[a].x4-p[c].x4,p[a].x5-p[c].x5);

          double dot = opdot(ab, ac) / sqrt(opdot(ab, ab)) / sqrt(opdot(ac, ac));

          if (dot > 0) {
            bener = false;
            //printf("%d %d %d %.7lf\n", a, b, c, dot);
          }  
        } else {
          // dua titik sama
        }
      }
    }

    if (bener) {
      ans.push_back(a+1);
    }
  }

  printf("%d\n", ans.size());
  for (int i=0; i<ans.size(); i++) {
    printf("%d\n", ans[i]);
  }
}