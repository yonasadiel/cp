#include <cstdio>
#include <vector>
#include <algorithm>
#define MAXP 500000
using namespace std;

int n,m;
int p[MAXP+5];
vector<int> prima;

void shieve() {
  for (int i=0; i<MAXP; i++) {
    p[i] = i;
  }
  for (int i=2; i<MAXP; i++) {
    if (p[i] == i) {
      prima.push_back(i);
      for (int j=2*i; j<MAXP; j+=i) {
        p[j] = i;
      }
    }
  }
}

int main() {
  shieve();

  scanf("%d%d",&n,&m);

  int dist = upper_bound(prima.begin(), prima.end(), n) - prima.begin();
  printf("%d %d\n", prima[dist], prima[dist]);
  int cnt = 0;
  for (; cnt<n-1; cnt++) {
    printf("%d %d %d\n", cnt+1, cnt+2, (cnt==0)?prima[dist]-n+2:1);
  }
  for (int i=1; i<=n && cnt < m; i++) {
    for (int j=i+2; j<=n && cnt < m; j++) {
      printf("%d %d %d\n", i, j, 100000000);
      cnt++;
    }
  }

}