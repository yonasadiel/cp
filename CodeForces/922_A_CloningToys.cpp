#include <cstdio>
using namespace std;

int main() {
  int x,y;
  scanf("%d%d",&x,&y);
  y--;
  if (x < y || y < 0) {
    printf("No\n");
    return 0;
  }

  x -= y;
  if (x&1 || (y == 0 && x!=0)) {
    printf("No\n");
  } else {
    printf("Yes\n");
  }
}