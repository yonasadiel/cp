#include <iostream>

using namespace std;

int main() {
    int x;
    scanf("%d",&x);
    int a,b;
    a = x; b = 0;
    while (a > 0) {
      b *= 10;
      b += a%10;
      a /= 10;
    }
    printf("%d\n", x < b);
    return 0;
}