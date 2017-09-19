#include <cstdio>
#include <algorithm>
using namespace std;

int n;
long long    arr[200005];
long long temple[200005];
long long tempri[200005];
long long  prele[200005];
long long  preri[200005];

int main() {
  scanf("%d",&n);
  for (int i=0; i<n; i++) {
    scanf("%I64d",&arr[i]);
  }

  prele[0] = 0;
  temple[0] = arr[0];
  for (int i=1; i<n; i++) {
    temple[i] = max(arr[i], temple[i-1]+1);
    prele[i] = prele[i-1] + temple[i] - arr[i];
  }

  preri[n-1] = 0;
  tempri[n-1] = arr[n-1];
  for (int i=n-2; i>=0; i--) {
    tempri[i] = max(arr[i], tempri[i+1]+1);
    preri[i] = preri[i+1] + tempri[i] - arr[i];
  }

  long long minn = min(preri[0], prele[n-1]);
  for (int i=0; i+1<n; i++) {
    if (temple[i] != tempri[i+1]) minn = min(minn, prele[i] + preri[i+1]);
    else {
      minn = min(minn, min(prele[i] + preri[i], prele[i+1] + preri[i+1]));
    }
  }

  printf("%I64d\n", minn);
}