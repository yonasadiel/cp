#include <cstdio>
using namespace std;

int main() {
  int n;
  scanf("%d",&n);

  if (n == 0) {
    printf("2\n");
  } else if (n == 1) {
    printf("1\n");
  } else {
    long long a = 2, b = 1, temp;
    for (int i=1; i<n; i++) {
      temp = a;
      a = b;
      b = b + temp;
    }
    printf("%lld\n", b);
  }
}