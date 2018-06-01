#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int s[200];
int p[200];
int c[200][200];

bool komp(int a, int b) {
  return p[a] < p[b];
}

bool taken[200];

int jalan(int pos) {
  int ret;
  if (pos == n) {
    ret = 0;
  } else {
    if (s[pos] == 1) {
      ret = 1+jalan(pos+1);
    } else {
      if (p[pos] == 0) {
        ret = 1+jalan(pos+1);
      } else if (p[pos] == 1) {
        ret = -1;
        if (!taken[c[pos][0]]) {
          taken[c[pos][0]] = true;
          ret = 2+jalan(pos+1);
          taken[c[pos][0]] = false;
        }
        ret = max(ret, 1+jalan(pos+1));
      } else {
        int ret1=-1, ret2=-1;
        if (!taken[c[pos][0]]) {
          taken[c[pos][0]] = true;
          ret1 = 2+jalan(pos+1);
          taken[c[pos][0]] = false;
        }
        if (!taken[c[pos][1]]) {
          taken[c[pos][1]] = true;
          ret2 = 2+jalan(pos+1);
          taken[c[pos][1]] = false;
        }
        if (ret1 == -1 && ret2 == -1) {
          ret = 1+jalan(pos+1);
        } else {
          ret = max(ret1, ret2);
        }
      }
    }
  }

  //printf("%d %d\n", pos, ret);
  return ret;
}

int main() {
  int t;
  scanf("%d",&t);
  while (t--) {
    int urut[200];
    memset(taken, false, sizeof taken);
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
      urut[i] = i;
      scanf("%d",&s[i]);
    }

    for (int i=0; i<n; i++) {
      scanf("%d",&p[i]);
      for (int j=0; j<p[i]; j++) {
        scanf("%d",&c[i][j]);
      }
    }

    printf("%d\n", jalan(0));

  }
}