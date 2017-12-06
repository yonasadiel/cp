#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int e[2];
int a,b;
int cnt;

int main() {
  cnt = 0;
  
  scanf("%d%d%d",&n,&e[0],&e[1]);
  sort(e, e+2);
  for (int i=0; i<n; i++) {
    scanf("%d%d",&a,&b);
    if (a < b) {
      if (a >= e[0]) cnt++;
    } else {
      if (a <= e[1]) cnt++;
    }
  }
  printf("%d\n",cnt);
  
}