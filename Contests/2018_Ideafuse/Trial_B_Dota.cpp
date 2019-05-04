#include <bits/stdc++.h>
using namespace std;

void solve(int tc) {
  int a, b, c;
  scanf("%d%d%d",&a,&b,&c);
  printf("Case #%d: %d %d\n", tc, 150+a*19, 13*c);
}

int main() {
  int t;
  scanf("%d", &t);
  for (int i = 1; i <= t; i++)
    solve(i);
}