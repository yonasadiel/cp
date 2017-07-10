#include<bits/stdc++.h>
using namespace std;

int FPB(int a,int b) {
	if (a<b) swap(a,b);
	if (b==0) return a;
	return FPB(b,a%b);
}

int main () {
	int satu,dua,jumlah;
	scanf("%d",&jumlah);
	for (int i=1; i<=jumlah; i++) {
		scanf("%d %d",&satu,&dua);
		printf("%d\n",FPB(satu,dua));
	}
	return 0;
}
