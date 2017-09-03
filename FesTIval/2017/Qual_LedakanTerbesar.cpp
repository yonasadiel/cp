#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <utility>
#include <queue>
#define pii pair<int,int>
#define pr first
#define pc second
#define mp make_pair
using namespace std;

int dr[] = {0, 1, -1, 0};
int dc[] = {1, 0, 0, -1};

void main_per_case(int kasus){
  int r,c;
  char pet[100][100];
  scanf("%d %d\n",&r,&c);
  for (int i=0; i<r; i++) {
    for (int j=0; j<c; j++) {
      scanf("%c",&pet[i][j]);
    } scanf("\n");
  }

  int maks = 0;
  queue <pii> antri;

  for (int i=0; i<r; i++) {
    for (int j=0; j<c; j++) {
      if (pet[i][j] == '*') {
        antri.push(mp(i,j));
        pet[i][j] = '-';
        int fnd = 1;

        while(!antri.empty()) {
          pii top = antri.front();
          antri.pop();

          for (int i=0; i<4; i++) {
            int rn = top.pr + dr[i];
            int cn = top.pc + dc[i];

            if (rn >=0 && cn >=0 && rn < r && cn < c && pet[rn][cn] == '*') {
              antri.push(mp(rn,cn));
              fnd++;
              pet[rn][cn] = '-';
            }
          }
        }

        maks = max(maks, fnd);
      }
    }
  }

  printf("Case #%d: %d\n", kasus, maks);
}

int main(){
  int t;
  scanf("%d",&t);
  for (int t_i=1; t_i<=t; t_i++) {
    main_per_case(t_i);
  }
}