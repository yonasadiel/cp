#include <cstdio>
using namespace std;

int main() {
  long long a,b;
  scanf("%I64d%I64d", &a, &b);
  while (a>0 && b>0) {
    if(a >= 2*b) { a%=2*b; } else if (b >= 2*a) { b %= 2*a; } else { break; }
  }
  printf("%I64d %I64d\n", a, b);
}