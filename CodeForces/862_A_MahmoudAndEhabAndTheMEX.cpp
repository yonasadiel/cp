#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int arr[106];
int ada = 0;

int main() {
  int n,x,xx,cnt = 0;
  scanf("%d%d",&n,&x);
  for (int i=0; i<n; i++) {
    scanf("%d",&arr[i]);
    if (arr[i] == x) ada = 1;
    if (arr[i] < x) cnt++;
  }

  printf("%d\n", ((cnt < x) ? x-cnt : 0) + ada);
}