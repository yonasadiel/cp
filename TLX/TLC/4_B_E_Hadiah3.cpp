#include<bits/stdc++.h>
using namespace std;

long long pangkat[65],b;

void daftar() {
	pangkat[0]=1;
	for (int k=1; k<=39; k++) {
		pangkat[k]=pangkat[k-1]*3;
//		printf("%lld\n",pangkat[k]);
	}	

}

stack<long long> tumpukan;

int main() {
	daftar();
	scanf("%lld",&b);
	long long c=b;	
	for (int k=39; k>=0; k--) {
		if (c>=pangkat[k]) {
			while (c>=pangkat[k]) {
				tumpukan.push(pangkat[k]);
				c-=pangkat[k];
			}
		}
	}
	printf("%d\n",tumpukan.size());
	while (!tumpukan.empty()) {
		printf("%lld",tumpukan.top());
		tumpukan.pop();
		if (!tumpukan.empty()) {
			printf(" ");
		}
	}
	printf("\n");

}
