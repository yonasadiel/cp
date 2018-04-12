#include <iostream>

using namespace std;

int sumDigit(int x) {
  int ans = 0;
  while (x > 0) {
    ans += x%10;
    x /= 10;
  }
  return ans;
}

int main() {
  int n, a=0;
  scanf("%d", &n);
  while (n > 0) {
    n -= sumDigit(n);
    a++;
  }
  printf("%d\n", a+1);
}