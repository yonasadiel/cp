#include <cstdio>
#include <cstring>
using namespace std;

int n,k,m;
int arr[100005];
int sett[100005];

int main() {
  memset(sett, 0, sizeof sett);
  scanf("%d%d%d", &n, &k, &m);
  for (int i=0; i<n; i++) {
    scanf("%d",&arr[i]);
    sett[arr[i]%m]++;
  }

  int get = -1;
  for (int i=0; i<m && get == -1; i++) {
    if (sett[i] >= k) {
      get = i;
    }
  }

  if (get == -1) {
    printf("No\n");
  } else {
    printf("Yes\n");
    int cnt = 0;
    for (int i = 0; i<n && cnt < k; i++) {
      if (arr[i] %m == get) {
        if (cnt != 0) {
          printf(" ");
        }
        cnt++;
        printf("%d", arr[i]);
      }
    }
    printf("\n");
  }
}