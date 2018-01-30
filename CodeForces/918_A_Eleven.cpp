#include <cstdio>
#include <cstring>
using namespace std;

bool fibo[20005];

int main() {
  memset(fibo, false, sizeof fibo);
  int n, a, b, c;

  scanf("%d",&n);
  a=1, b=1;
  fibo[1] = true;
  for (; b < 5000; ) {
    c = a+b;
    fibo[c] = true;
    a = b, b = c;
  }

  for (int i=1; i<=n; i++) {
    if (fibo[i]) printf("O");
    else printf("o");
  }
  printf("\n");
}