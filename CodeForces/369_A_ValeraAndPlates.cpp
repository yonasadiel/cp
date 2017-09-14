#include <cstdio>
#include <algorithm>
using namespace std;

int n,b,p,c,r=0;
int s[]={0,0,0};

int main() {
  scanf("%d%d%d",&n,&b,&p);
  for (int i=0; i<n; i++) { scanf("%d",&c); s[c]++; }

  int bowl = min(b, s[1]);
  s[1] -= bowl;
  b    -= bowl;

  r += s[1];

  int plate = min(b, s[2]);
  s[2] -= plate;
  b    -= plate;

  plate = min(p, s[2]);
  s[2] -= plate;
  p    -= plate;

  r += s[2];

  printf("%d\n", r);
}