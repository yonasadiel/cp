#include <cstdio>
#include <cstring>
using namespace std;

int n;
int a[100];
int b[100];

int main() {
  scanf("%d",&n);
  for (int i=0; i<n; i++) {
    scanf("%d",&a[i]);
  }
  memset(b, 0, sizeof b);
  for (int i=0; i<n; i++) {
    for (int j=i+1; j<n; j++) {
      b[a[i]+a[j]] = 1;
    }
  }
  int cnt = 0;
  for (int i=0; i<100; i++) {
    if (b[i]) cnt++;
  }
  printf("%d\n", cnt);
  
}