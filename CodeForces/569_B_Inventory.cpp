#include <cstdio>
#include <cstring>
using namespace std;

int arr[200005];
bool sudah[200005];

int main() {
  memset(sudah, false, sizeof sudah);
  int n;
  scanf("%d",&n);
  for (int i=0; i<n; i++) {
    scanf("%d",arr+i);
  }
  for (int i=0; i<n; i++) {
    if (sudah[arr[i]] || arr[i] > n) {
      arr[i] = -1;
    } else {
      sudah[arr[i]] = true;
    }
  }
  int o = 1;
  for (int i=0; i<n; i++) {
    if (arr[i] == -1) {
      while (sudah[o]) { o++; }
      arr[i] = o++;
    }
  }
  for (int i=0; i<n; i++) {
    printf("%d", arr[i]);
    if (i == n-1) printf("\n");
    else printf(" "); 
  }

}