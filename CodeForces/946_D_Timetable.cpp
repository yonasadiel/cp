#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m, k;
char c[505][505];
int ma = 0;
vector<int> opt[505];
bool debug = false;
int dp[505][505];

int play(int pos, int rem) {
  int& ret = dp[pos][rem];
  if (ret != -1) return ret;
  if (pos == n) { ret = 0; }
  else {
    ret = play(pos+1, rem);
    for (int i=0; i<opt[pos].size() && i<=rem; i++) {
      ret = max(ret, opt[pos][i] + play(pos+1, rem-i));
    }
  }
  //fprintf(stderr, "%d %d %d\n", pos, rem, ret);
  return ret;
}

int main() {
  scanf("%d%d%d",&n,&m,&k);
  for (int i=0; i<n; i++) {
    scanf("\n");
    for (int j=0; j<m; j++) {
      scanf("%c", &c[i][j]);
    }
  }

  for (int i=0; i<n; i++) {
    int mii = -1;
    int maa = -2;
    for (int j =0; j<m; j++) {
      if (c[i][j] == '1') {
        if (mii == -1) { mii = j; }
        maa = j;
      }
    }
    ma += maa - mii + 1;
  }

  for (int i=0; i<n; i++) {
    int cur;

    vector<int> l;
    l.push_back(0);
    cur = -1;
    for (int j=0; j<m; j++) {
      if (c[i][j] == '1') {
        if (cur != -1) { l.push_back(cur); } else { cur = 0; }
      } if (cur != -1) cur++;
    }
    if (cur != -1) l.push_back(l[l.size()-1]+1);

    vector<int> r;
    r.push_back(0);
    cur = -1;
    for (int j=m; j>=0; j--) {
      if (c[i][j] == '1') {
        if (cur != -1) { r.push_back(cur); } else { cur = 0; }
      } if (cur != -1) cur++;
    }
    if (cur != -1) r.push_back(r[r.size()-1]+1);

    for (int j=0; j<l.size()-1; j++) {
      int maaa = l[j] + r[0];
      for (int k=0; k<j; k++) {
        maaa = max(maaa, l[k] + r[j-k]);
      }
      opt[i].push_back(maaa);
      fprintf(stderr, "%d ", maaa);
    }
    if (cur!= -1) { opt[i].push_back(opt[i][opt[i].size()-1]+1); fprintf(stderr, "%d ", opt[i][opt[i].size()-1]); }
    fprintf(stderr, "\n");
  }

  memset(dp, -1, sizeof dp);
  fprintf(stderr, "%d\n", ma);
  printf("%d\n", ma-play(0, k));
}