#include <cstdio>
using namespace std;

int n,m,k;
char pet[2005][2005];

int main() {
  scanf("%d%d%d\n", &n,&m,&k);
  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      scanf("%c",&pet[i][j]);
    }
    scanf("\n");
  }

  int sum = 0;
  // horizontal
  for (int i=0; i<n; i++) {
    int str = 0;
    for (int j=0; j<m; j++) {
      if (pet[i][j] == '.') {
        str++;
      } else {
        if (str > 0) {
          if (str - k+1 > 0) { sum += str-k+1; }
          str = 0;
        }
      }
    }
    if (str > 0) {
      if (str - k+1 > 0) { sum += str-k+1; }
      str = 0;
    }
  }

  // vertikal
  for (int j=0; j<m; j++) {
    int str = 0;
    for (int i=0; i<n; i++) {
      if (pet[i][j] == '.') {
        str++;
      } else {
        if (str > 0) {
          if (str - k+1 > 0) { sum += str-k+1; }
          str = 0;
        }
      }
    }
    if (str > 0) {
      if (str - k+1 > 0) { sum += str-k+1; }
      str = 0;
    }
  }
  printf("%d\n", (k==1)?sum/2:sum);
}