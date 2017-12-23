#include <cstdio>
using namespace std;

int main() {
  char pet[10][10];
  int r,c;

  for (int i=0; i<9; i++) {
    for (int j=0; j<9; j++) {
      scanf("%c", &pet[i][j]);
      if (j%3 == 2) { scanf(" "); }
    }
    scanf("\n");
    if (i%3 == 2) { scanf("\n"); }
  }
  scanf("%d%d",&r,&c);
  r--; c--;

  int rn=r%3, cn=c%3, ada=0;
  for (int i=rn*3; i<(rn+1)*3; i++) {
    for (int j=cn*3; j<(cn+1)*3; j++) {
      if (pet[i][j] == '.') { ada = 1; pet[i][j] = '!'; }
    }
  }

  if (!ada) {
    for (int i=0; i<9; i++) {
    for (int j=0; j<9; j++) {
      if (pet[i][j] == '.') pet[i][j] = '!';
    }
    }
  }

  for (int i=0; i<9; i++) {
    for (int j=0; j<9; j++) {
      printf("%c",pet[i][j]);
      if (j==8) printf("\n");
      else if (j%3 == 2) printf(" ");
    }
    if (i ==2 || i==5) printf("\n");
  }
}