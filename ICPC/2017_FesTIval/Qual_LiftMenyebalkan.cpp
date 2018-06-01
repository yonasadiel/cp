#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <cstring>
using namespace std;

int lnt[1000005];

void main_per_case(int kasus){
  int n,x,y,a,b;
  scanf("%d%d%d%d%d",&n,&x,&y,&a,&b);
  memset(lnt, -1, sizeof lnt);

  queue<int> antri;
  antri.push(x);
  lnt[x] = 0;

  while (!antri.empty()) {
    int lntnow = antri.front();
    antri.pop();

    if (lntnow+a <= n && lnt[lntnow+a] == -1) {
      antri.push(lntnow+a);
      lnt[lntnow+a] = lnt[lntnow]+1;
    }
    if (lntnow-b >  0 && lnt[lntnow-b] == -1) {
      antri.push(lntnow-b);
      lnt[lntnow-b] = lnt[lntnow]+1;
    }
  }

  if (lnt[y] != -1) {
    printf("Case #%d: %d\n",kasus, lnt[y]);
  } else {
    printf("Case #%d: Pakai tangga saja\n", kasus);
  }
}

int main(){
  int t;
  scanf("%d",&t);
  for (int t_i=1; t_i<=t; t_i++) {
    main_per_case(t_i);
  }
}