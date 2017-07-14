#include <cstdio>
#include <utility>
#include <algorithm>
#include <vector>
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
using namespace std;

const int left_point = 1;
const int right_point = 0;

int n;
vector<pii> p;
int a,b;

int main() {
  scanf("%d",&n);
  for (int i=0; i<n; i++) {
    scanf("%d%d",&a, &b);
    p.push_back(mp(a, left_point));
    p.push_back(mp(b, right_point));
  }

  sort(p.begin(), p.end());

  int sz = 0;
  long long ret = 0;
  for (int i=0; i<p.size(); i++) {
    if (p[i].se == left_point) {
      ret += (long long) sz;
      sz++;
    } else {
      sz--;
    }
  }

  printf("%lld\n", ret);
}