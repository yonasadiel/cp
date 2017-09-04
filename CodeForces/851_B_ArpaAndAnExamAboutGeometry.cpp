#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
  long long ax, ay, bx, by, cx, cy;
  scanf("%I64d%I64d",&ax,&ay);
  scanf("%I64d%I64d",&bx,&by);
  scanf("%I64d%I64d",&cx,&cy);

  if ((ax-bx)*(ax-bx)+(ay-by)*(ay-by) == (cx-bx)*(cx-bx)+(cy-by)*(cy-by) &&
      (ax-bx)*(by-cy) != (bx-cx)*(ay-by)) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
}