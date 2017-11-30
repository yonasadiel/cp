#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
char pet[3005][3005];
bool bisa[3005][3005];

int main() {
  scanf("%d\n",&n);
  for (int i=0; i<n; i++) {
    for (int j=0; j<i+1; j++) {
      scanf("%c",&pet[i][j]);
    } scanf("\n");
  }
  
  memset(bisa, false, sizeof bisa);
  for (int i=0; i<n; i++) {
    char cm = 'z';
    for (int j=0; j<i+1; j++) {
      if (i == 0 || (j!=i && bisa[i-1][j]) || (j!=0 && bisa[i-1][j-1]))
        cm = min(cm, pet[i][j]);
    }
    for (int j=0; j<i+1; j++) {
      if (pet[i][j] == cm && (i == 0 || (j!=i && bisa[i-1][j]) || (j!=0 && bisa[i-1][j-1]))) {
        bisa[i][j] = true;
      }
    }
    printf("%c",cm);
  } printf("\n");
}