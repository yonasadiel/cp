#include <cstdio>
using namespace std;

int sum(int n) {
  while (n > 0) {
    return n%10 + sum(n/10);
  }
  return 0;
}

int main() {
  int i,j,k;

  scanf("%d",&k);
  for (i=1, j=1; j<k; i++) {
    if (10-sum(i) >= 0) j++;
  }
  while (10-sum(i) < 0) i++;
  printf("%d%d\n", i, 10-sum(i));

}