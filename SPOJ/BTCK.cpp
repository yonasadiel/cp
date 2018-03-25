#include <cstdio>
#include <algorithm>
using namespace std;

long long k;
long long arr[10];
long long ans[10];

void exec() {
  for (int i=0; i<10; i++) {
    scanf("%lld",&arr[i]);
  }
  scanf("%lld",&k);

  for (int i=0; i<10; i++) {
    ans[i] = i;
  }

  do {
    long long sum = 0;
    for (int i=0; i<10; i++) {
      sum += (ans[i] * arr[i]);
    }
    if (sum <= k) {
      for (int i=0; i<10; i++) {
        printf("%d", ans[i]);
        if (i == 9) {
          printf("\n");
        } else {
          printf(" ");
        }
      }
      return;
    }
  } while (next_permutation(ans, ans+10));
  printf("-1\n");

}

int main() {
  int t;
  scanf("%d",&t);
  while (t--) {
    exec();
  }
}