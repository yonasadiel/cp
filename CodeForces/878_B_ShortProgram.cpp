#include <cstdio>
#define MAXD 10
using namespace std;

int n;
int poss[MAXD];
char opr;
int opn;

int main() {
  for (int i=0; i<MAXD; i++) { poss[i] = 0; }

  scanf("%d\n",&n);
  for (int i=0; i<n; i++) {
    scanf("%c %d\n", &opr, &opn);

    int opnn = opn;
    if (opr == '&') {
      for (int i=0; i<MAXD; i++) {
        if (opnn % 2 == 0) {
          poss[i] = 1; // pasti nol
        }
        opnn /= 2;
      }
    }
    if (opr == '|') {
      for (int i=0; i<MAXD; i++) {
        if (opnn&1) {
          poss[i] = 2; // pasti satu
        }
        opnn /= 2;
      }
    }
    if (opr == '^') {
      for (int i=0; i<MAXD; i++) {
        if (opnn&1) {
          if      (poss[i] == 1) { poss[i] = 2; } // pasti satu
          else if (poss[i] == 2) { poss[i] = 1; } // pasti nol
          else if (poss[i] == 0) { poss[i] = 3; } // negasi
          else if (poss[i] == 3) { poss[i] = 0; } // kembali
        }
        opnn /= 2;
      }
    }
    //printf("%c %d ", opr, opn); for (int i=0; i<MAXD; i++) { printf("%d", poss[i]); } printf("\n");
  }

  int dan    = 1023;
  int atau   = 0;
  int toogle = 0;

  for (int i=0, j=1; i<MAXD; i++, j*=2) {
    if      (poss[i] == 1) { dan -= j; }
    else if (poss[i] == 2) { atau += j; }
    else if (poss[i] == 3) { toogle += j; }
  }

  int cnt = 0;
  if (dan    != 1023) cnt++;
  if (atau   !=    0) cnt++;
  if (toogle !=    0) cnt++;

  printf("%d\n", cnt);
  if (dan    != 1023) printf("& %d\n", dan);
  if (atau   !=    0) printf("| %d\n", atau);
  if (toogle !=    0) printf("^ %d\n", toogle);
}

/*
&
1 1 1
1 0 0
0 1 0
0 0 0

|
1 1 1
1 0 1
0 1 1
0 0 0

^
1 1 0
1 0 1
0 1 1
0 0 0
*/