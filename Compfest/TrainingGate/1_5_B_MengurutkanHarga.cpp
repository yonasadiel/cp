#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int n;
	int arr[105];

  scanf("%d",&n);
  for (int i=0; i<n; i++) {
    scanf("%d",&arr[i]);
  }

  for (int i=0; i<n; i++) {
    for (int j=i+1; j<n; j++) {
      if (arr[i] > arr[j]) {
        swap(arr[i],arr[j]);
        printf("%d %d\n",i+1, j+1);
      }
    }
  }
}