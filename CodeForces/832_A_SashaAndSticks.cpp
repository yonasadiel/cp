#include <cstdio>

long long n,k;

int main() {
  scanf("%I64d%I64d",&n,&k);
  if ((n/k)%2 == 0) {
    printf("NO\n");
  } else {
    printf("YES\n");
  }
}