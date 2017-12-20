#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
#define pii pair<int,int>
#define DBG if (debug)
using namespace std;

const bool debug = false;

int k,n;
char str[2500][5000];
char ts[5000];
char cc;
vector<pii> pos;
vector<int> ib;
bool kembar;

int main() {
  scanf("%d%d\n",&k,&n);
  for (int i=0; i<k; i++) {
    scanf("%s",str[i]);
  }

  for (int i=1; i<k; i++) {
    for (int j=0; j<n; j++) {
      if (str[i][j] != str[i-1][j]) {
        ib.push_back(j);
        DBG printf("%d ", j);
      }
    }
    if (!ib.empty()) {
      strcpy(ts, str[i]);
      break;
    }
  }
  DBG printf("\n");

  if (ib.empty()) {
    cc = str[0][0];
    str[0][0] = str[0][1];
    str[0][1] = cc;
    printf("%s\n", str[0]);
    return 0;
  }

  if (ib.size() > 4) {
    printf("-1\n");
    return 0;
  }

  kembar = false;
  for (int i=0; i<n; i++) {
    for (int j=i+1; j<n; j++) {
      if (ts[i] == ts[j]) kembar = true;
    }
  }

  if (kembar && ib.size() == 2) {
    ib.push_back(ib[0]);
  }

  int ansa = -1, ansb = -1;
  for (int ita=0; ita<ib.size(); ita++) {
    for (int tb=0; tb<n; tb++) {
      int ta = ib[ita];

      cc=ts[ta]; ts[ta]=ts[tb]; ts[tb]=cc;

      DBG printf("%s", ts);
      bool bisa = true;
      vector<int> bed;
      for (int i=0; i<k && bisa; i++) {
        bed.clear();
        for (int j=0; j<n; j++) {
          if (ts[j] != str[i][j]) bed.push_back(j);
        }
        if (bed.size() == 2) {
          if (ts[bed[0]] == str[i][bed[1]] &&
              ts[bed[1]] == str[i][bed[0]]) {
            //
          } else {
            bisa = false;
            DBG printf(" %d 1", i);
          }
        } else if (bed.size() == 0) {
          if (kembar) {
            //
          } else {
            bisa = false;
            DBG printf(" %d 2", i);
          }
        } else {
          bisa = false;
          DBG printf(" %d 3", i);
        }
      }
      DBG printf("\n");

      if (bisa) {
        ansa = ta;
        ansb = tb;
      }

      cc=ts[ta]; ts[ta]=ts[tb]; ts[tb]=cc;
    }
  }

  if (ansa == -1) {
    printf("-1\n");
  } else {
    DBG printf("%d %d\n", ansa, ansb);
    cc=ts[ansa]; ts[ansa]=ts[ansb]; ts[ansb]=cc;
    printf("%s\n", ts);
  }
}