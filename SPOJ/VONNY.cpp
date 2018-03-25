#include <cstdio>
using namespace std;

int arr[7][8];
bool domino[7][7];
bool placed[7][8];
int ans;

bool available(int a, int b) {
  if (a<b) return domino[a][b];
  return domino[b][a];
}

void unavail(int a, int b) {
  if (a<b) domino[a][b] = false;
  else domino[b][a] = false;
}

void avail(int a, int b) {
  if (a<b) domino[a][b] = true;
  else domino[b][a] = true;
}

void bt(int rn, int cn) {
  if (rn == 7) {
    ans++;
  } else if (cn == 8) {
    bt(rn+1, 0);
  } else if (placed[rn][cn]) {
    bt(rn, cn+1);
  } else {
    if (cn != 7 && !placed[rn][cn+1] && available(arr[rn][cn], arr[rn][cn+1])) {
      unavail(arr[rn][cn], arr[rn][cn+1]);
      placed[rn][cn+1] = true;
      placed[rn][cn] = true;
      bt(rn, cn+2);
      placed[rn][cn+1] = false;
      placed[rn][cn] = false;
      avail(arr[rn][cn], arr[rn][cn+1]);
    }
    if (rn != 6 && !placed[rn+1][cn] && available(arr[rn][cn], arr[rn+1][cn])) {
      unavail(arr[rn+1][cn], arr[rn][cn]);
      placed[rn+1][cn] = true;
      placed[rn][cn] = true;
      bt(rn, cn+1);
      placed[rn+1][cn] = false;
      placed[rn][cn] = false;
      avail(arr[rn+1][cn], arr[rn][cn]);
    }
  }
}

void exec() {
  for (int i=0; i<7; i++)
    for (int j=0; j<7; j++)
      domino[i][j] = true;
  for (int i=0; i<7; i++)
    for (int j=0; j<8; j++)
      placed[i][j] = false;


  for (int i=0; i<7; i++) {
    for (int j=0; j<8; j++) {
      scanf("%d",&arr[i][j]);
    }
  }

  ans = 0;
  bt(0,0);

  printf("%d\n", ans);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    exec();
  }
}