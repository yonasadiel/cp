#include <cstdio>
using namespace std;

long long a,b;

int main() {
  scanf("%I64d%I64d", &a, &b);
  if (b%10 < a%10 || b-a > 10) {
    printf("0\n");
  } else {
    long long ans = 1;
    for (long long i = a+1; i <= b; i++) {
      ans *= i;
      ans %=10;
    }
    printf("%I64d\n", ans%10);
  }
}