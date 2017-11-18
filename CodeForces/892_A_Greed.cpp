#include <cstdio>
#include <algorithm>
using namespace std;

long long m[100005];

int main() {
  long long n,a;
  long long sum=0;
  scanf("%I64d",&n);
  for (int i=0; i<n; i++) {
    scanf("%I64d",&a);
    sum += a;
  }
  for (int i=0; i<n; i++) {
    scanf("%I64d",&m[i]);
  }
  sort(m, m+n);
  long long two = m[n-1] + m[n-2];
  if (sum <= two) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }
}