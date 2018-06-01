#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n,m;
long long sudah[2000];
vector<long long>a,b;
long long c[1005];

long long f(int ai, int bi) {
  return a[ai]*b[bi] + c[(a[ai]*b[bi])%m];
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    a.clear();
    b.clear();

    long long dummy;
    scanf("%d%d",&n,&m);

    memset(sudah, -1, sizeof sudah);
    for (int i=0; i<n; i++) {
      scanf("%lld",&dummy);
      if (sudah[dummy%m] == -1) {
        sudah[dummy%m] = dummy;
      } else {
        sudah[dummy%m] = min(sudah[dummy%m], dummy);
      }
    }
    for (int i=0; i<m; i++) {
      if (sudah[i] != -1) {
        a.push_back(sudah[i]);
      }
    }

    memset(sudah, -1, sizeof sudah);
    for (int i=0; i<n; i++) {
      scanf("%lld",&dummy);
      if (sudah[dummy%m] == -1) {
        sudah[dummy%m] = dummy;
      } else {
        sudah[dummy%m] = min(sudah[dummy%m], dummy);
      }
    }
    for (int i=0; i<m; i++) {
      if (sudah[i] != -1) {
        b.push_back(sudah[i]);
      }
    }

    for (int i=0; i<m; i++) {
      scanf("%lld",&c[i]);
    }

    long long mini = f(0,0);
    for (int ia=0; ia < a.size(); ia++) {
      for (int ib=0; ib < b.size(); ib++) {
        mini = min(mini, f(ia, ib));
      }
    }

    printf("%lld\n", mini);
  }
}