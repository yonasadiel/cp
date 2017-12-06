#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <queue>
using namespace std;

int n,m,k;
int** arr;

vector<int> adj[100005];
int degin[100005];
int perm[100005];
queue<int> q;

int main() {
  memset(degin, 0, sizeof(degin));
  memset(perm, -1, sizeof(perm));
  
  scanf("%d%d%d",&n,&k,&m);
  arr = (int**) malloc(n * sizeof(int*));
  for (int i=0; i<n; i++) {
    arr[i] = (int*) malloc(m * sizeof(int));
    for (int j=0; j<m; j++) {
      scanf("%d",&arr[i][j]);
    }
  }
  int permnow = 1;
  bool bisa = true;
  
  for (int i=0; i<n-1; i++) {
    int j=0;
    while (j < m && arr[i][j] == arr[i+1][j]) { j++; }
    if (j == m) bisa = false;
    else {
      adj[arr[i][j]].push_back(arr[i+1][j]);
      degin[arr[i+1][j]]++;
    }
  }
  
  bool ada = false;
  for (int i=0; i<k; i++) {
    if (!ada && degin[i] == 0 && i != arr[0][0]) {
      perm[i] = 0;
      ada = true;
      q.push(i);
    }
  }
  if (!ada) bisa = false;
  else {
    for (int i=0; i<k; i++) {
      if (degin[i] == 0 && perm[i] == -1) {
        perm[i] = permnow++;
        q.push(i);
      }
    }
  }
  
  while (!q.empty()) {
    int curk = q.front(); q.pop();
    
    for (int i=0; i<adj[curk].size(); i++) {
      int ne = adj[curk][i];
      degin[ne]--;
      if (degin[ne] == 0) {
        if (perm[ne] != -1 && perm[ne] < perm[curk]) { bisa = false; }
        else {
          perm[ne] = permnow++;
          q.push(ne);
        }
      }
    }
  }
  
  for (int i=0; i<k; i++) {
    if (perm[i] == -1) {
      bisa = false;
    }
  }
  if (!bisa) {
    printf("-1\n");
  } else {
    printf("%d", perm[0]);
    for (int i=1; i<k; i++) {
      printf(" %d", perm[i]);
    } printf("\n");
  }
}