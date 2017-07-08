#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d",&n);
	printf("%d\n",n/2);
	if (n%2 == 0) {
		for (int i=0; i<n/2; i++) {
			printf("2");
			if (i==n-1) printf("\n");
			else printf(" ");
		}
	} else {
		for (int i=0; i<(n-3)/2; i++) {
			printf("2 ");
		}
		printf("3\n");
	}
}
