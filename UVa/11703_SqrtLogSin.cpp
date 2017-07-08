#include<bits/stdc++.h>
using namespace std;

long long x[1000005];

long long cari(int indeks) {
	if (indeks==0) return 1; //base case
	if (x[indeks]!=-1) return x[indeks];
	int satu=indeks-sqrt(indeks);
	int dua =log(indeks);
	int tiga=indeks*sin(indeks)*sin(indeks);
	x[indeks]=(cari(satu) + cari(dua) + cari(tiga))%1000000;
	return x[indeks];
}

int main() {
	int masukan;
	bool ulang=true;
	memset(x,-1,sizeof x);
	while (ulang) {
		scanf("%d",&masukan);
		if (masukan==-1) return 0;
		printf("%lld\n",cari(masukan));		
	}
	return 0;
}
