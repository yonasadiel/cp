#include <cstdio>
using namespace std;

int main() {
  int x,z,y = 0;

  scanf("%d",&x);
  while (x%10 == 0 && x > 0) {
    x /= 10;
  }
  z = x;
  while (z > 0) {
    y *= 10;
    y += z%10;
    z /= 10;
  }

  printf("%s\n", (y == x)? "YES" : "NO");

}