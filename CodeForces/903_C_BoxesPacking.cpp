#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
int a[10000];
int maxx[10000];

int main() {
  scanf("%d",&n);
  for (int i=0; i<n; i++) {
    scanf("%d",&a[i]);
  }
  sort(a, a+n);

  memset(maxx, -1, sizeof maxx);
  for (int i=0; i<n; i++) {
    int j=0;
    while (a[i] <= maxx[j]) { j++; }

    maxx[j] = a[i];
  }

  int cnt = 0;
  for (; maxx[cnt] != -1;) {
    cnt++;
  }
  printf("%d\n", cnt);
}