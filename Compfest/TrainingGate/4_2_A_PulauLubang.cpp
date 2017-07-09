#include <cstdio>
#include <algorithm>
using namespace std;

int n,m;
char petak[105][105];
int dx[] = {0,1,-1,0};
int dy[] = {1,0,0,-1};

bool valid (int r, int c) {
  return (r >= 0 && r < n && c >= 0 && c < m);
}

int dfs(int a, int b) {
  int ret = 1;
  petak[a][b] = '#';

  for (int i=0; i<4; i++) {
    int an = a + dx[i];
    int bn = b + dy[i];
    if (valid(an,bn) && petak[an][bn] == '.') {
      ret += dfs(an,bn);
    }
  }

  return ret;
}

int main() {
  scanf("%d%d",&n,&m);

  for (int i=0; i<n; i++) {
    scanf("%c",&petak[i][0]);
    for (int j=0; j<m; j++) {
      scanf("%c",&petak[i][j]);
    }
  }

  int maks = 0;
  int cnt = 0;
  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      if (petak[i][j] == '.') {
        maks = max(maks,dfs(i,j));
        cnt++;
      }
    }
  }

  printf("%d %d\n",cnt,maks);
}