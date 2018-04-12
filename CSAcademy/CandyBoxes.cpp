#include <cstdio>
#include <queue>
using namespace std;

int n,m;
int arr[100005];
queue<int> q;

int main() {
  scanf("%d%d",&n,&m);
  for (int i=0; i<n; i++) {
    scanf("%d", &arr[i]);
  }
  int x,y=0;
  for (int i=0; i<m; i++) {
    scanf("%d",&x);
    if (x == 1) {
      scanf("%d", &x); x--;
      if (arr[x] == 0) {
        printf("%d\n", x+1);
        y--;
      } else {
        arr[x]--;
      }
    } else {
      y++;
    }
  }
  while (y>0) {
    printf("1\n");
    y--;
  }
}