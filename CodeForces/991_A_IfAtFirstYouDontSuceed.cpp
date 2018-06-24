#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define DEBUG if (debug)
using namespace std;

int n, a, b, c;

int main() {
  scanf("%d%d%d%d", &a, &b, &c, &n);
  int ans = n-a-b+c;
  if (ans >= 1 && c <= a && c <= b) {
    printf("%d\n", ans);
  } else {
    printf("-1\n");
  }
}