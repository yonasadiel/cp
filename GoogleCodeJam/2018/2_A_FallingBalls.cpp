#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int ar[200];
char ans[200][200];

void solve(int tc) {
  scanf("%d", &n);
  for (int i=0; i<n; i++)
    scanf("%d", &ar[i]);
  
  bool bisa = true;
  if (ar[0] == 0) bisa = false;
  if (ar[n-1] == 0) bisa = false;

  if (bisa) {
    int dest[200];
    printf("Case #%d: ", tc);

    for (int from=0, to=0, acc=0; to<n ; to++) {
      for (int j=0; j<ar[to]; from++, j++) {
        dest[from] = to;
      }
    }
    for (int i=0; i<200; i++)
      for (int j=0; j<200; j++)
        ans[i][j] = '.';

    int row = 1;
    for (int i=0; i<n; i++) {
      if (dest[i] < i) {
        for (int j=i; j>dest[i]; j--) {
          ans[i-j][j] = '/';
          row = max(row, i-j+2);
        }
      } else {
        for (int j=i; j<dest[i]; j++) {
          ans[j-i][j] = '\\';
          row = max(row, j-i+2);
        }
      }
    }

    printf("%d\n", row);
    for (int i=0; i<row; i++) {
      for (int j=0; j<n; j++) {
        printf("%c", ans[i][j]);
      }
      printf("\n");
    }

  } else {
    printf("Case #%d: IMPOSSIBLE\n", tc);
  }
}

int main() {
  int t;
  scanf("%d", &t);
  for (int i=1; i<=t; i++) {
    solve(i);
  }
}