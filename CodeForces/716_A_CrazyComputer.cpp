#include <cstdio>
using namespace std;

int a[100005];

int main() {
  int n,c,k=0;
  scanf("%d%d",&n,&c);
  for (int i=0; i<n; i++) {
    scanf("%d",&a[i]);
    if (i!=0 && a[i] - a[i-1] > c) {
      k = 1;
    } else {
      k++;
    }
  }
  printf("%d\n", k);
}