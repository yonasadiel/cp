#include <cstdio>
using namespace std;

int r,c;
char pet[100][100];

int dr[5][4][4] = {
  {
    {0, 0, 1, 1},
    {0, 0, 1, 1},
    {0, 0, 1, 1},
    {0, 0, 1, 1}
  }, {
    {0, 0, 0, 0},
    {0, 1, 2, 3},
    {0, 0, 0, 0},
    {0, 1, 2, 3}
  }, {
    {0, 0, 1, 1},
    {0, 1, 1, 2},
    {0, 0, 1, 1},
    {0, 1, 1, 2}
  }, {
    {0, 0, 1, 1},
    {0, 1, 1, 2},
    {0, 0, 1, 1},
    {0, 1, 1, 2}
  }, {
    {0, 1, 1, 1},
    {0, 1, 1, 2},
    {0, 0, 0, 1},
    {0, 1, 1, 2}
  }
};
int dc[5][4][4] = {
  {
    {0, 1, 0, 1},
    {0, 1, 0, 1},
    {0, 1, 0, 1},
    {0, 1, 0, 1}
  }, {
    {0, 1, 2, 3},
    {0, 0, 0, 0},
    {0, 1, 2, 3},
    {0, 0, 0, 0},
  }, {
    {0, 1, 0, -1},
    {0, 0, 1, 1},
    {0, 1, 0, -1},
    {0, 0, 1, 1}
  }, {
    {0, 1, 1, 2},
    {0, -1, 0, -1},
    {0, 1, 1, 2},
    {0, -1, 0, -1}
  }, {
    {0, -1, 0, 1},
    {0, 0, 1, 0},
    {0, 1, 2, 1},
    {0, -1, 0, 0}
  }
};

bool in_bound(int tr, int tc) {
  return tr >= 0 && tr < r && tc >= 0 && tc < c;
}


int main() {
  scanf("%d%d\n",&r,&c);
  for (int i=0; i<r; i++) {
    for (int j=0; j<c; j++) {
      scanf("%c",&pet[i][j]);
    }
    scanf("\n");
  }

  int cntx[] = {0,0,0,0,0};

  for (int i=0; i<r; i++) {
    for (int j=0; j<c; j++) {

      if (pet[i][j] != '.' && pet[i][j] != '#') {
        for (int t=0; t<5; t++) {
          for (int r=0; r<4; r++) {
            int cnt = 0;
            for(int k=0; k<4; k++) {
              int ni = i+dr[t][r][k];
              int nj = j+dc[t][r][k];
              if (in_bound(ni, nj) && pet[i][j] == pet[ni][nj]) {
                cnt++;
              }
            }

            if (cnt == 4) {
              for(int k=0; k<4; k++) {
                int ni = i+dr[t][r][k];
                int nj = j+dc[t][r][k];
                pet[ni][nj] = '#';
              }
              cntx[t]++;
              // printf("%d\n", t);
              t = 20;
              break;
            }
          } // end loop r
        } // end loop t

        /*for (int ni = 0; ni < r; ni++) {
          for (int nc = 0; nc < c; nc++) {
            printf("%c",pet[ni][nc]);
          }
          printf("\n");
        }
        printf("\n");*/
      } // end if . nor #
    }
  }

  for (int i=0; i<5; i++) {
    printf("%d\n", cntx[i]);
  }
}