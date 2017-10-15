#include <cstdio>
using namespace std;

int arr[1000];

int main() {
  int n, cnt = 1, max = -1;
  scanf("%d",&n);
  for (int i=0; i<n; i++) {
    scanf("%d",&arr[i]);
    if (i > 0 && arr[i] > max) {
      cnt++;
    }
    max = (arr[i] > max)? arr[i] : max;
  }
  printf("%d\n",cnt);
}