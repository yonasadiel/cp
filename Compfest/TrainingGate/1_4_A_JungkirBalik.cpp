#include <cstdio>
using namespace std;

int main() {
	int n;
	int arr[105];
	scanf("%d",&n);
	for (int i=0; i<n; i++) {
		scanf("%d",&arr[i]);
	}
	for (int i=n-1; i>=0; i--) {
		printf("%d\n",arr[i]);	
	}
}