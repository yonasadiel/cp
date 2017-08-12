#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,m;
int arr[2005];
int brr[2005];
int dp[2005][2005][2];

int dist(int from, int to) {
  return min((m+from-to)%m, (m+to-from)%m);
}

int ngedp(int a, int b, int last) {
  int &ret = dp[a][b][last];
  
  if (ret != -1) {
    return ret;
  } else if (a == n && b == n) {
    ret = 0;
  } else if (b == n) {
    if (last == 0) { ret = dist(arr[a], arr[a-1]) + ngedp(a+1, b, 0); }
    if (last == 1) { ret = dist(arr[a], brr[b-1]) + ngedp(a+1, b, 0); }
  }  else if (a == n) {
    if (last == 0) { ret = dist(brr[b], arr[a-1]) + ngedp(a, b+1, 1); }
    if (last == 1) { ret = dist(brr[b], brr[b-1]) + ngedp(a, b+1, 1); }
  }else {
    int reta, retb;
    if (last == 0) { reta = dist(arr[a], arr[a-1]) + ngedp(a+1, b, 0); }
    if (last == 1) { reta = dist(arr[a], brr[b-1]) + ngedp(a+1, b, 0); }
    if (last == 0) { retb = dist(brr[b], arr[a-1]) + ngedp(a, b+1, 1); }
    if (last == 1) { retb = dist(brr[b], brr[b-1]) + ngedp(a, b+1, 1); }
    ret = min(reta,retb);
  }
  return ret;
}

void percase() {
  memset(dp, -1, sizeof dp);
  scanf("%d%d",&m, &n);
  for (int i=0; i<n; i++) { scanf("%d", &arr[i]); }
  for (int i=0; i<n; i++) { scanf("%d", &brr[i]); brr[i] = (brr[i]+m/2)%m; }
  printf("%d\n",min(dist(0, arr[0]) + ngedp(1,0,0), dist(0, brr[0]) + ngedp(0,1,1)));
}

int main() {
  int t;
  scanf("%d",&t);
  while (t--) {
    percase();
  }
}