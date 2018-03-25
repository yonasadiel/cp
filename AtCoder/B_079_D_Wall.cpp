#include <cstdio>
#include <algorithm>
using namespace std;

int h,w;
int dist[15][15];

int main() {
  scanf("%d%d",&h,&w);
  for (int i=0; i<10; i++) {
    for (int j=0; j<10; j++) {
      scanf("%d",&dist[i][j]);
    }
  }

  for (int k=0; k<10; k++) {
    for (int j=0; j<10; j++) {
      for (int i=0; i<10; i++) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  int sum=0, x;
  for (int i=0; i<h; i++) {
    for (int j=0; j<w; j++) {
      scanf("%d",&x);
      if (x != -1) {
        sum += (int) dist[x][1];
      }
    }
  }
  printf("%d\n", sum);
}
