#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int t;
int cst[200005];
queue<int> q;

bool valid (int n) {
  return (n > 0 && n <= 200000);
}

int main() {
  scanf("%d",&t);
  while (t--) {
    memset(cst,-1,sizeof cst);

    int a,b;
    scanf("%d%d",&a,&b);

    cst[a] = 0;
    q.push(a);

    while (!q.empty()) {
      int cur = q.front();
      q.pop();

      //if (cur < 100) printf("DEBUG : %d %d\n",cur, cst[cur]);

      if (valid(cur+1) && (cst[cur+1] == -1 || cst[cur+1] > 1+cst[cur])) { cst[cur+1] = 1+cst[cur]; q.push(cur+1); }
      if (valid(cur-1) && (cst[cur-1] == -1 || cst[cur-1] > 1+cst[cur])) { cst[cur-1] = 1+cst[cur]; q.push(cur-1); }
      if (valid(cur*2) && (cst[cur*2] == -1 || cst[cur*2] > 2+cst[cur])) { cst[cur*2] = 2+cst[cur]; q.push(cur*2); }
      if (valid(cur*3) && (cst[cur*3] == -1 || cst[cur*3] > 3+cst[cur])) { cst[cur*3] = 3+cst[cur]; q.push(cur*3); }
      if (cur%2 == 0 && valid(cur/2) && (cst[cur/2] == -1 || cst[cur/2] > 2+cst[cur])) { cst[cur/2] = 2+cst[cur]; q.push(cur/2); }
      if (cur%3 == 0 && valid(cur/3) && (cst[cur/3] == -1 || cst[cur/3] > 3+cst[cur])) { cst[cur/3] = 3+cst[cur]; q.push(cur/3); }
    }

    printf("%d\n",cst[b]);
  }
}