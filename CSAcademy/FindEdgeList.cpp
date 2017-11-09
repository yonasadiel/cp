#include <cstdio>
#include <vector>
#include <utility>
#include <queue>
#include <cstring>
#include <map>
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
using namespace std;

int n,a,b;
vector<int> ayah[100006];
vector<int> ans;
vector<pii> ided;
map<pii, int> m;
int cntanak[100006];
int msize = 0;
int vis[100005];

int toId(pii ed) {
  if (m.count(ed) == 0) {
    m[ed] = msize++;
    ided.push_back(ed);
  }
  return m[ed];
}

pii toEdge(int id) {
  return ided[id];
}

int main() {
  memset(cntanak, 0, sizeof cntanak);
  memset(vis, false, sizeof vis);
  scanf("%d",&n);
  for (int i=0; i<n; i++) {
    int no = -1;
    scanf("%d",&a);
    for (int j=0; j<a; j++) {
      scanf("%d",&b);
      int ne = toId(mp(min(i+1, b), max(i+1, b)));
      if (no != -1) {
        cntanak[no]++;
        ayah[ne].push_back(no);
      }
      no = ne;
    }
  }

  queue<int> q;
  for (int i=0; i<msize; i++) {
    if (cntanak[i] == 0) {
      q.push(i);
      ans.push_back(i);
      vis[i] = true;
    }
  }

  while (!q.empty()) {
    int to = q.front();
    q.pop();

    for (int i=0; i<ayah[to].size(); i++) {
      int ay = ayah[to][i];
      cntanak[ay]--;
      if (cntanak[ay] == 0 && !vis[ay]) {
        q.push(ay);
        ans.push_back(ay);
        vis[ay] = true;
      }
    }
  }

  bool bisa = true;
  for (int i=0; i<msize; i++) {
    if (cntanak[i] > 0) bisa = false;
  }
  if (bisa) {
    for (int i=ans.size()-1; i>=0; i--) {
      pii p = toEdge(ans[i]);
      printf("%d %d\n", p.fi, p.se);
    }
  } else {
    printf("-1\n");
  }

}