#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n;
int a;
vector<int> chld[100005];
queue<int> q;
int dist[100005];

int main() {
  scanf("%d",&n);
  for (int i=1; i<n; i++) {
    scanf("%d",&a);
    chld[a-1].push_back(i);
  }

  int hei = 0;
  int leaf_cnt = 0;

  q.push(0);
  dist[0] = 0;

  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    for (int i=0; i<chld[cur].size(); i++) {
      int nxt = chld[cur][i];
      dist[nxt] = dist[cur]+1;
      q.push(nxt);

      hei = max(hei,dist[nxt]);
    }

    if (chld[cur].size() == 0) {
      leaf_cnt++;
    }
  }

  printf("%d %d\n", leaf_cnt, hei);
}