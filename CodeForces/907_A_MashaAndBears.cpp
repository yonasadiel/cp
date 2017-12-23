#include <cstdio>
using namespace std;

int main() {
  int a,b,c,m,f=0;
  scanf("%d%d%d%d",&a,&b,&c,&m);

  for (int i=0; !f && i<=205; i++)
  for (int j=0; !f && j<=205; j++)
  for (int k=0; !f && k<=205; k++) {
    if (a   <= i && b   <= j && c   <= k &&
        m   <= i && m   <= j && m   <= k &&
        2*a >= i && 2*b >= j && 2*c >= k &&
        2*m <  i && 2*m <  j && 2*m >= k &&
        i > j && j > k) {
      printf("%d\n%d\n%d\n", i, j, k);
      f=1;
    }
  }

  if (!f) {
    printf("-1\n");
  }
}