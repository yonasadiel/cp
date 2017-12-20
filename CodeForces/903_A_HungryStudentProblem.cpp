#include <cstdio>
#include <cstring>
using namespace std;

bool bisa[200];

void dfs(int pos) {
  bisa[pos] = true;
  if (pos+3 < 150 && !bisa[pos+3]) dfs(pos+3);
  if (pos+7 < 150 && !bisa[pos+7]) dfs(pos+7);
}

int main() {
  memset(bisa, false, sizeof bisa);
  dfs(0);

  int n,x;

  scanf("%d",&n);
  for (int i=0; i<n; i++) {
    scanf("%d",&x);
    if (bisa[x]) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
}