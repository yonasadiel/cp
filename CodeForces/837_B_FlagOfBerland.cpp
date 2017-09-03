#include <cstdio>
using namespace std;

int main() {
  int n,m;
  char p[105][105];

  scanf("%d%d\n",&n,&m);
  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      scanf("%c",&p[i][j]);
    } scanf("\n");
  }

  bool bener = false;
  if (n%3 == 0) {
    // horizontal
    bool tebak = true;
    bool sudah[100]; sudah['R'-'A'] = false; sudah['G'-'A'] = false; sudah['B'-'A'] = false;
    for (int i=0; i<n; i++) {
      for (int j=0; j<m; j++) {
        if (p[i][j] != p[(i/(n/3))*n/3][0]) { tebak = false; }
        sudah[p[i][j] - 'A'] = true;
      }
    }
    if (tebak) { if (sudah['R'-'A'] && sudah['G'-'A'] && sudah['B'-'A']) bener = true; }
  }
  if (m%3 == 0) {
    // vertikal
    bool tebak = true;
    bool sudah[100]; sudah['R'-'A'] = false; sudah['G'-'A'] = false; sudah['B'-'A'] = false;
    for (int i=0; i<n; i++) {
      for (int j=0; j<m; j++) {
        if (p[i][j] != p[0][(j/(m/3))*m/3]) { tebak = false; }
        sudah[p[i][j] - 'A'] = true;
      }
    }
    if (tebak) { if (sudah['R'-'A'] && sudah['G'-'A'] && sudah['B'-'A']) bener = true; }
  }

  if (bener) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }


}