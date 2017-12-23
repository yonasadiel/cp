#include <cstdio>
using namespace std;

int main() {
  int n,m,l,r;
  char s[200];
  char c1,c2;

  scanf("%d %d\n",&n,&m);
  scanf("%s",s);
  for (int i=0; i<m;i++) {
    scanf("%d %d %c %c\n",&l, &r, &c1, &c2);
    l--; r--;
    for (int j=l; j<=r; j++) {
      if (s[j] == c1) s[j] = c2;
    }
  }
  printf("%s\n", s);
}