#define fi first
#define se second
#include<bits/stdc++.h>
using namespace std;

int n,m,k;
int dr[4] = {0,1,0,-1};
int dc[4] = {1,0,-1,0};
pair<int,int> lake[5000]; //fi luas lakenya | se nomor lake
int petak[55][55];
/* petak explanation
 * 0 = darat
 * 1 = air
 * 2 = ocean
 * x = array x
 */

bool valid (int rn, int cn) {
  return (rn > 0 && cn > 0 && rn <= n && cn <= m);
}

int ff (int rn, int cn, int c) {
  int ret = 1;
  petak[rn][cn] = c;
  for (int i = 0; i < 4; i++) {
    int rb = rn + dr[i];
    int cb = cn + dc[i];
    if (valid(rb,cb) && petak[rb][cb] == 1) {
      //cout<<"change "<<rb<<","<<cb<<" to "<<c<<endl;
      ret += ff(rb,cb,c);
    }
  }
  return ret;
}

void printCheck() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      printf("%d ",petak[i][j]);
    }
    printf("\n");
  }
}

int main() {
  scanf("%d%d%d",&n,&m,&k);

  char dumm;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      scanf("%c",&dumm);
      if (dumm == '*') petak[i][j] = 0; //darat
      if (dumm == '.') petak[i][j] = 1; //air
    }
  }

  //printCheck();

  /*FLOOD FILL OCEAN*/
  for (int i = 1; i <= n; i++) {
    if (petak[i][1] == 1) ff(i,1,2);
    if (petak[i][m] == 1) ff(i,m,2);
  }
  for (int i = 1; i <= m; i++) {
    if (petak[1][i] == 1) ff(1,i,2);
    if (petak[n][i] == 1) ff(n,i,2);
  }

  //cout<<"flood fill ocean"<<endl;
  //printCheck();

  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (petak[i][j] == 1) {
        cnt++;
        lake[cnt] = make_pair(ff(i,j,cnt+2),cnt+2);
        //cout<<"nemu lake nomor "<<cnt+2<<endl;
        //printCheck();
      }
    }
  }

  sort(lake+1,lake+cnt+1);
  //printCheck();

  int luas = 0;
  for (int o = 1; o <= cnt-k; o++) {
    luas += lake[o].fi;
  }

  printf("%d\n",luas);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      char out = '.';
      if (petak[i][j] == 0) out = '*';
      if (petak[i][j] == 1) out = '.';
      if (petak[i][j] == 2) out = '.';
      for (int o = 1; o <= cnt-k; o++) {
        if (petak[i][j] == lake[o].se) {
          out = '*';
        }
      }
      printf("%c",out);
    }
    printf("\n");
  }

}
