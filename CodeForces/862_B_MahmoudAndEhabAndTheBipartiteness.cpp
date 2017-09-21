#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

vector<int> adj[100005];
int color[100005];
int a,b;

int main() {
  memset(color, -1, sizeof color);

  int n;
  scanf("%d",&n);
  for (int i=0; i<n-1; i++) {
    scanf("%d%d",&a,&b);
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  long long cnt[] = {0,0};

  queue<int> q;

  cnt[0]++;
  color[1] = 0;
  q.push(1);

  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    for (int i=0; i<adj[cur].size(); i++) {
      int nex = adj[cur][i];
      if (color[nex] == -1) {
        color[nex] = 1-color[cur];
        cnt[color[nex]]++;
        q.push(nex);
      }
    }
  }

  long long ans = cnt[0] * cnt[1] - ((long long) (n-1));
  printf("%I64d\n", ans);
}