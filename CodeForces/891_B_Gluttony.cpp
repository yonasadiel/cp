#include <cstdio>
#include <algorithm>
#include <utility>
using namespace std;

int n;
pair<int,int> a[30];
int b[30];

int main() {
  scanf("%d", &n);
  for (int i=0; i<n; i++) {
    scanf("%d",&a[i].first);
    a[i].second = i;
  }

  sort(a, a+n);
  for (int i=0; i<n; i++) {
    b[a[i].second] = a[(i+1)%n].first;
  }
  for (int i=0; i<n-1; i++) {
    printf("%d ", b[i]);
  } printf("%d\n", b[n-1]);
}