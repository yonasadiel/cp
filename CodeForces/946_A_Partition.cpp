#include <cstdio>
using namespace std;

int main() {
  int n,x,s=0;
  scanf("%d",&n);
  for (int i=0; i<n; i++) {
    scanf("%d",&x);
    if (x>0) s+=x; else s-=x;
  }
  printf("%d\n", s);
}