#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int n, q;
int o,a,b;
char s[1005];

int main() {
  scanf("%d%d\n",&n,&q);
  scanf("%s",&s);
  for (int i=0; i<q; i++) {
    scanf("%d%d%d",&o,&a,&b);
    if (o == 1) {
      swap(s[a-1],s[b-1]);
    } else {
      reverse(s+a-1, s+b);
    }
  }

  printf("%s\n",s);
}