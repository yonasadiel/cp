#include <cstdio>
#include <vector>
using namespace std;

int n,m,q;
int a,b;
vector<int> adj[100005];

int main() {
  scanf("%d%d",&n,&m);
  for (int i=0; i<m; i++) {
    scanf("%d%d",&a,&b);
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  int ganjil = 0;
  for (int i=1; i<=n; i++) {
    if (adj[i].size() % 2 == 1) {
      ganjil++;
    }
  }

  if (ganjil == 0) {
    printf("Tipe A\n");
  } else if (ganjil <= 2) {
    printf("Tipe B\n");
  } else {
    printf("Tipe C\n");
  }

}