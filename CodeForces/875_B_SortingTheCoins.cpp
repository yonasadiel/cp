#include <cstdio>
#include <cstring>
using namespace std;

int n;
int arr[300005];

int main() {
  scanf("%d",&n);
  for (int i=0; i<n; i++) {
    arr[i] = 0;
  } arr[n] = 1;

  printf("1");
  int sum = 1;
  int last = n-1;
  int x;
  for (int i=0; i<n; i++) {
    scanf("%d", &x);
    x--;

    arr[x] = 1;

    if (x == last) {
      last--;
      for (int j=last; j>=0 && arr[j] == 1; j--) {
        sum--;
        last--;
      }
    } else {
      sum++;
    }

    printf(" %d", sum);
  }
  printf("\n");
}