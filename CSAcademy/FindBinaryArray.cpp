#include <cstdio>
using namespace std;

int n;
int le[100005];
int ri[100005];
int po[100005];

int main() {
  scanf("%d",&n);
  for (int i=0; i<n; i++) {
    scanf("%d",&le[i]);
  }
  for (int i=0; i<n; i++) {
    scanf("%d",&ri[i]);
  }
  
  for (int i=0;i<n; i++) {
    if (i == 0) {
      if (le[i+1] > le[i]) { po[i] = 0; }
      else                 { po[i] = 1; }
    } else {
      if (ri[i-1] > ri[i]) { po[i] = 0; }
      else                 { po[i] = 1; }
    }
  }
  for (int i=0; i<n; i++) {
    printf("%d",po[i]);
  }
  printf("\n");
}