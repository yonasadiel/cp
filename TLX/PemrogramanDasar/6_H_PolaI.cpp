#include <bits/stdc++.h>

int main() {
	
	int N,j,k = 0;
	scanf("%d %d",&N,&k);
	
	for (j=1;j<=N;j++){
		if (j%k==0) {
			printf("*");
			if (j!=N) printf(" ");
			continue;
		}
		
		printf("%d",j);
		if (j!=N) printf(" ");
	}
	printf("\n");
	return 0;
}
