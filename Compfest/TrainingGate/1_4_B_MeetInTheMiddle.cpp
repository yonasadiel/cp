#include <cstdio>
using namespace std;

int main() {
	int n,arr[105];
	scanf("%d",&n);
	for (int i=0; i<n; i++) {
		scanf("%d",&arr[i]);
	}
	for (int i=0; i<n/2; i++) {
		if (i!=0) printf(" ");
		printf("%d %d", arr[i],arr[n-1-i]);
	}
	if (n%2 == 1) {
		if (n/2 != 0) printf(" ");
		printf("%d",arr[n/2]);
	}
	printf("\n");
}