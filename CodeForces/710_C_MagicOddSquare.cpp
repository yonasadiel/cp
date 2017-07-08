#include<bits/stdc++.h>
using namespace std;

int n;
int arr[50][50];

void make(int r, int c, int a) {
	arr[r][c] = a;
	int rn = ( r - 1 + n ) % n;
	int cn = ( c + 1 ) % n;
	if (arr[rn][cn] != -1) {
		rn = ( r + 1 ) % n;
		cn = c;
	}
	if (arr[rn][cn] != -1) {
		return;
	}
	make(rn,cn,a+1);
}

int main() {
	memset(arr,-1,sizeof arr);
	scanf("%d",&n);
	make(0,(n+1)/2-1,1);
	for (int i=0; i<n; i++) {
		printf("%d",arr[i][0]);
		for (int j=1; j<n; j++) {
			printf(" %d",arr[i][j]);
		}
		printf("\n");
	}
}
