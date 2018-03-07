#include <cstdio>
using namespace std;

int main() {
  int n, c=0;
  scanf("%d",&n);
  for (int i=1; i<n; i++) {
    if (n%i == 0) c++;
  }
  printf("%d\n", c);
}