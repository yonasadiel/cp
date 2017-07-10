#include<bits/stdc++.h>
using namespace std;

long long a,b,c,n;

long long hitung(long long bawah, long long atas) {
	if (atas==0) return 1;
	if (atas==1) return bawah;
	long long ret = hitung(bawah,atas/2)%n;
	if (atas%2==0) {
		return (ret*ret)%n;
	} else {
		return ((ret*ret)%n*bawah)%n;
	}
	
}

int main() {
	scanf("%lld%lld%lld%lld",&a,&b,&c,&n);
	long long hasil=a;
	for (int i=0; i<c; i++) {
		hasil=hitung(hasil,b);
	}
	printf("%lld\n",hasil%n+1);
	
}
