#include <cstdio>
using namespace std;

int a[305][305];
int b[605][605];

int main() {
  int h, w, x, y;
  scanf("%d%d%d%d", &h,&w,&x,&y);
  for (int i=0; i<h+x; i++) {
    for (int j=0; j<w+y; j++) {
      scanf("%d", &b[i][j]);
    }
  }
  
  for (int i=0; i<h; i++) {
    for (int j=0; j<w; j++) {
      if (i<x || j<y) {
        a[i][j] = b[i][j];
      } else {
        a[i][j] = b[i][j] - a[i-x][j-y];
      }
    }
  }
  
  for (int i=0; i<h; i++) {
    for (int j=0; j<w; j++) {
      printf("%d", a[i][j]);
      printf("%c", (j==w-1)?'\n':' ');
    }
  }
  
}