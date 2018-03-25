#include <cstdio>
using namespace std;

int n,m;
char pet[100][100];

int main() {
  scanf("%d%d\n",&n,&m);
  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      scanf("%c", &pet[i][j]);
    }
    scanf("\n");
  }

  bool bisa = true;
  for (int i=0; i<n; i++) {
    bool ada = false;
    for (int j=0; j<m; j++) {
      if (pet[i][j] == '#') { ada = true; }
    }
    for (int ii=i+1; ii<n; ii++) {
      int ik = 0;
      for (; pet[i][ik] == '.' && pet[ii][ik] == '.'; ik++);
      if (pet[i][ik] == pet[ii][ik]) {
        for (int ij=0; ij<m; ij++) {
          if (pet[ii][ij] != pet[i][ij]) bisa = false;
        }
      } else if (ik != m) {
        for (int ij=0; ij<m; ij++) {
          if (pet[ii][ij] == '#' && pet[i][ij] == '#') bisa = false;
        }
      }
    }
  }

  if (bisa) {
    printf("Yes\n");
  } else {
    printf("No\n"); 
  }
}