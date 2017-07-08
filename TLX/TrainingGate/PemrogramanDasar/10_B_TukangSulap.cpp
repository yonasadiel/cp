#include<bits/stdc++.h>
using namespace std;

int ar[3][1005];
int n,q;

int ubah(char a) {
	if (a=='A') return 0;
	if (a=='B') return 1;
}

int main() {
	scanf("%d",&n);
	for (int i=0; i<n; i++) {
		scanf("%d",&ar[0][i]);
	}
	for (int i=0; i<n; i++) {
		scanf("%d",&ar[1][i]);
	}
	
	scanf("%d",&q);
	for (int i=0; i<q; i++) {
		int e,d;
		char f,g;
		scanf("%c%c %d %c %d",&f,&f,&e,&g,&d);
		swap(ar[ubah(f)][e-1],ar[ubah(g)][d-1]);
	}
	
	for (int i=0; i<n-1; i++) {
		printf("%d ",ar[0][i]);
	}   printf("%d\n",ar[0][n-1]);
	for (int i=0; i<n-1; i++) {
		printf("%d ",ar[1][i]);
	}   printf("%d\n",ar[1][n-1]);
	
}
