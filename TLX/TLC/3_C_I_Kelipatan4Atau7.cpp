#include<bits/stdc++.h>
using namespace std;

int main() {
	long long jumlah;
	scanf("%lld", &jumlah);
	while (jumlah--) {
		long long n,tujuh,empat,dualapan;
		long long total=0;
		scanf("%lld",&n);
		dualapan=n/28;
		tujuh=n/7;
		empat=n/4;
		total+=(7+tujuh*7)*tujuh/2;
		total+=(4+empat*4)*empat/2;
		total-=(28+dualapan*28)*dualapan/2; 
		printf("%lld\n",total);
	}
}


