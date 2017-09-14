#include <cstdio>
#include <algorithm>
#include <utility>
using namespace std;

int n;
pair<int,int> arr[105];

int main() {
  scanf("%d",&n);
  for (int i=0; i<n; i++) { scanf("%d",&arr[i].first); arr[i].second=i; }
  sort(arr, arr+n);

  int i=0, j=n-1;
  while (i<j) {
    printf("%d %d\n", arr[i].second+1, arr[j].second+1);
    i++; j--;
  }
}