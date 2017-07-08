#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,k;
int arr[10];

void permut(int pos, int last) {
  if (pos == n+1) {
    bool toogle[10]; memset(toogle, false, sizeof(toogle));
    for (int i=1; i<=n; i++) {
      if (toogle[arr[i]]) {
        return;
      } else {
        toogle[arr[i]] = true;
      }
    }

    for (int i=1; i<=n; i++) {
      if (i!=1) printf(" ");
      printf("%d",arr[i]);
    }
    printf("\n");
  } else {
    for (int i=max(1,last-k); i<=min(n,last+k); i++) {
      arr[pos] = i;
      permut(pos+1, i);
    }
  }
}

int main() {
  scanf("%d%d",&n,&k);
  for (int i=1; i<=n; i++) {
    arr[1] = i;
    permut(2, i);
  }
}