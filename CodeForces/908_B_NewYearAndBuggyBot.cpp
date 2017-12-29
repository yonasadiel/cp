#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int r,c;
char pet[55][55];
char s[150];
int sr, sc;

int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};

bool valid(int rn, int cn) {
  return rn >= 0 && cn >= 0 && rn < r && cn < c;
}

int main() {
  scanf("%d%d\n",&r,&c);
  for (int i=0; i<r; i++) {
    for (int j=0; j<c; j++) {
      scanf("%c",&pet[i][j]);
      if (pet[i][j] == 'S') { sr = i; sc = j; }
    }
    scanf("\n");
  }
  scanf("%s",s);

  int n = strlen(s);
  int perm[] = {0, 1, 2, 3};
  int ans = 0;

  do {
    int cr = sr, cc = sc;
    bool bisa = true;
    for (int i=0; i<n && bisa; i++) {
      if (pet[cr][cc] == '#') { bisa = false; break; }
      if (pet[cr][cc] == 'E') break;
      cr += dr[perm[s[i] - '0']];
      cc += dc[perm[s[i] - '0']];
      if (!valid(cr, cc)) { bisa = false; break; }
    }
    if (bisa && pet[cr][cc] == 'E') { ans++; }
  } while (next_permutation(perm, perm+4));

  printf("%d\n", ans);
}