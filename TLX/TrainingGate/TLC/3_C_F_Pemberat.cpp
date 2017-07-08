#include<bits/stdc++.h>
using namespace std;

long long pangkat[65],a,b;

void daftar() {
	pangkat[0]=1;
	for (int k=1; k<=61; k++) {
		pangkat[k]=pangkat[k-1]*2;
//		printf("$lld",pangkat[k]);
	}	

}

int main() {
	daftar();
	scanf("%lld%lld",&a,&b);
	long long c=b-a;	
	for (int k=61; k>=0; k--) {
		if (c>=pangkat[k]) {
			printf("%lld\n",pangkat[k]);
			c-=pangkat[k];
		}
	}

}
