#include <cstdio>
#include <utility>
#include <algorithm>
#include <vector>
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
using namespace std;

int n,m;
vector<pii> p;
int a,b;

int main() {
  scanf("%d%d",&n,&m);
  for (int i=0; i<n; i++) {
    scanf("%d%d",&a, &b);
    p.push_back(mp(a,0));
    p.push_back(mp(b,1));
  }

  sort(p.begin(), p.end());

  int last = 1;
  int sz = 0;
  int ret = 0;
  for (int i=0; i<p.size(); i++) {
    if (sz == 0) { ret += min(m, p[i].fi) - last; }

    if (p[i].se == 0) {
      // beginning of line
      sz++;
    } else {
      // end of line
      sz--;
      last = min(m, p[i].fi);
    }
  }
  ret += m - last;

  printf("%d\n", ret);
}