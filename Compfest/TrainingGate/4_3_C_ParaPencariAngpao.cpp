#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <climits>
using namespace std;

int n,m,k;
int a,b;
int k_arr[10];
vector<int> adj[10005];
int dist[10005];
queue<int> q;

int main() {
  scanf("%d%d%d",&n,&m,&k);
  for (int i=0; i<m; i++) {
    scanf("%d%d",&a,&b);
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  for (int i=0; i<k; i++) {
    scanf("%d",&k_arr[i]);
  }
  k_arr[k] = 1;
  sort(k_arr, k_arr+k);

  int ret = INT_MAX;
  do {
    int ret_temp = 0;
    int cur = 1;
    for (int i=0; i<=k; i++) {
      memset(dist, -1, sizeof dist);

      dist[cur] = 0;
      q.push(cur);

      while (!q.empty()) {
        int pos = q.front();
        q.pop();

        for (int j=0; j<adj[pos].size(); j++) {
          int next = adj[pos][j];

          if (dist[next] == -1) {
            dist[next] = dist[pos] + 1;
            q.push(next);
          }
        }
      }
      ret_temp += dist[k_arr[i]];

      cur = k_arr[i];
    }

    ret = min(ret, ret_temp);
  } while (next_permutation(k_arr, k_arr+k));

  printf("%d\n", ret);
}