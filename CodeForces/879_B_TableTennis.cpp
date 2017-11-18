#include <cstdio>
#define ll long long
using namespace std;

ll n;
ll k;
int arr[1000];

int main() {
  scanf("%I64d%I64d",&n,&k);
  for (int i=0; i<n; i++) {
    scanf("%d", &arr[i]);
  }

  int max = arr[0];
  for (int i=1, j=0; j<k && i<n; i++) {
    if (arr[i] > max) {
      max = arr[i];
      j = 1;
    } else {
      j++;
    }
  }

  printf("%d\n", max);
}