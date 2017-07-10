#include <bits/stdc++.h>

int main() {
	
	int N,j,i;
	scanf("%d",&N);
	
	for (j=1;j<=N;j++){
		for (i=1;i<N+1-j;i++) {
			printf(" ");
		}
		for (i=1;i<=j;i++) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
