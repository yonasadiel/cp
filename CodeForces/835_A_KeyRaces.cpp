#include <cstdio>
using namespace std;

int main() {
  int s, va, vb, ta, tb;
  scanf("%d%d%d%d%d",&s,&va,&vb,&ta,&tb);
  if (s*va + 2*ta == s*vb + 2*tb) {
    printf("Friendship\n");
  } else if ((s*va + 2*ta < s*vb + 2*tb)) {
    printf("First\n");
  } else {
    printf("Second\n");
  }
}