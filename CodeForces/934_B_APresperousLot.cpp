#include <cstdio>
using namespace std;

int main() {
  int k;
  scanf("%d",&k);
  if (k > 18 * 2) {
    printf("-1\n");
  } else {
    while (k > 0) {
      if (k >= 2) { printf("8"); k-=2; }
      else { printf("6"); k-=1; }
    }
    printf("\n");
  }
}