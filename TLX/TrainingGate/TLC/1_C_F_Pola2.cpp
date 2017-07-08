#include <bits/stdc++.h>

int main() {
	
	int N,j,k = 0,i;
	scanf("%d",&N);
	
	for (j=1;j<=N;j++){
		for (i=1;i<=j;i++) {
			printf("%d",k%10);
			k++;
		}
		printf("\n");
	}
	return 0;
}
