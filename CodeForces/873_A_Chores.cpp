#include <cstdio>
using namespace std;

int main() {
  int n,k,x,t,c=0;
  scanf("%d%d%d",&n,&k,&x);
  for (int i=0; i<n; i++) {
    scanf("%d",&t);
    if (i < n-k) { c += t; }
    else { c += x; }
  }

  printf("%d\n", c);
}