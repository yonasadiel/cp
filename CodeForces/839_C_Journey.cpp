#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#define MAXN 100005
using namespace std;

int n;
int a,b;
vector<int> v[MAXN];
int dist[MAXN];
double prob[MAXN];

int main() {
  memset(dist, -1, sizeof dist);

  scanf("%d",&n);
  for (int i=0; i<n-1; i++) {
    scanf("%d%d",&a,&b);
    v[a].push_back(b);
    v[b].push_back(a);
  }

  queue<int> q;
  q.push(1);
  dist[1] = 0;
  double sum = 0;
  prob[1] = 1;

  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    bool end = true;

    int vs = 0;
    for (int i=0; i<v[cur].size(); i++) {
      int next = v[cur][i];
      if (dist[next] == -1) { vs++; }
    }
    for (int i=0; i<v[cur].size(); i++) {
      int next = v[cur][i];
      if (dist[next] == -1) {
        dist[next] = dist[cur] + 1;
        prob[next] = prob[cur] * 1.0 / vs;
        //printf("%.8lf\n", prob[next]);
        end = false;
        q.push(next);
      }
    }

    if (end) { sum += prob[cur] * 1.0 * dist[cur]; }
  }

  printf("%.8lf\n", (double) sum);
}