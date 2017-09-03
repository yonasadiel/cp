#include <cstdio>
using namespace std;

int main() {
  int n,a;
  bool bisa = false;
  scanf("%d",&n);
  for (int i=0; i<n; i++) {
    scanf("%d",&a);
    if (a&1) { bisa = true; }
  }
  if (bisa) {
    printf("First\n");
  } else {
    printf("Second\n");
  }
}