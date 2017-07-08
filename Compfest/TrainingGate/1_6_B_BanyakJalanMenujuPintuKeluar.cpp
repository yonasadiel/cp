#include <cstdio>
using namespace std;

int rec(int r, int c) {
  if (r == 1 || c == 1) return 1;
  return rec(r-1,c)+rec(r,c-1);
}

int main() {
  int n,m;
  scanf("%d%d",&n,&m);
  printf("%d\n",rec(n,m));
}