#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <map>
#include <set>
#define ll long long
#define pb push_back
#define fi first
#define se second
#define mp make_pair
using namespace std;

int n;
int a[5005];

int main() {
  scanf("%d",&n);
  for (int i=0; i<n; i++) {
    scanf("%d",&a[i]);
  }
  
  int mad[5005];
  for (int i=0;i<n; i++) {
    int dl[5005]; dl[i]=0;
    for (int j=(i+1)%n; j!=i; j=(j+1)%n) {
      dl[j] = dl[(j+n-1)%n] + a[(j+n-1)%n];
    }
    //dumpln(dl, n);
    int dr[5005]; dr[i]=0;
    for (int j=(i+n-1)%n; j!=i; j=(j+n-1)%n) {
      dr[j] = dr[(j+1)%n] + a[j%n];
    }
    //dumpln(dr, n);
    mad[i] = 0;
    for (int j=0; j<n; j++) {
      mad[i] = max(mad[i], min(dr[j], dl[j]));
    }
  }
  int mi = 0;
  for (int i=0; i<n; i++) {
    if (mad[i] < mad[mi]) mi = i;
  }
  printf("%d\n", mi+1);
  return 0;
}