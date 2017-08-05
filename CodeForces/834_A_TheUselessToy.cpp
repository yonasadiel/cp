#include <cstdio>
using namespace std;

int trans(char c) {
  int n;
  if (c == '^') n = 0;
  if (c == '>') n = 1;
  if (c == 'v') n = 2;
  if (c == '<') n = 3;
  return n;
}
int main() {
  char a,b;
  int m,n,o;
  scanf("%c %c",&a,&b);
  n = trans(a);
  m = trans(b);
  scanf("%d",&o);
  if (o%4 == (4+n-m)%4 && o%4 == (4+m-n)%4) {
    printf("undefined\n");
  } else if (o%4 == (4+m-n)%4) {
    printf("cw\n");
  } else {
    printf("ccw\n");
  }
}