#include <cstdio>
using namespace std;

void pindah(int level, int dari, int ke) {
  if (level == 1) {
    printf("%d %c %c\n", level, 'A'+dari, 'A'+ke);
  } else {
    pindah(level-1, dari, 3-dari-ke);
    printf("%d %c %c\n", level, 'A'+dari, 'A'+ke);
    pindah(level-1, 3-dari-ke, ke);
  }
}

int main() {
  int n;
  scanf("%d",&n);
  pindah(n,0,2);
}