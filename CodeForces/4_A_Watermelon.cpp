#include <cstdio>
using namespace std;

int main() {
  int n;
  scanf("%d",&n);
  if (n<3 || n&1) {
    printf("NO\n");
  } else {
    printf("YES\n");
  }
}