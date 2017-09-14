#include <cstdio>
using namespace std;

int main() {
  long long a,b;
  scanf("%I64d%I64d", &a, &b);
  int cnt = 0;
  while (a <= b) {
    cnt++;
    a*=3;
    b*=2;
  }
  printf("%d\n", cnt);
}