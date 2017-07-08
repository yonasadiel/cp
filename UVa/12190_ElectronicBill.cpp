#include<bits/stdc++.h>
using namespace std;

long long uangkecwh(long long k) {
	long long res=0;
	res+=min((long long)200,k)/2;
	k-=min((long long)200,k);
	res+=min((long long)29700,k)/3;
	k-=min((long long)29700,k);
	res+=min((long long)4950000,k)/5;
	k-=min((long long)4950000,k);
	res+=k/7;
	k-=k;
	return res;
}

long long cwhkeuang(long long k) {
	long long res=0;
	res+=min(k,(long long)100)*2;
	k-=min(k,(long long)100);
	res+=min(k,(long long)9900)*3;
	k-=min(k,(long long)9900);
	res+=min(k,(long long)990000)*5;
	k-=min(k,(long long)990000);
	res+=k*7;
	k-=k;
	return res;
}

int main() {
	long long a,b;
	scanf("%lld%lld",&a,&b);
	while(a!=0 && b!=0) {
		
		long long c=uangkecwh(a);
		long long kiri=0,kanan=c;
		long long hasil=10e9;
		while(kiri<=kanan) {
			long long tengah=(kiri+kanan)/2;
			long long sel=abs(cwhkeuang(c-tengah)-cwhkeuang(tengah));
			if (sel==b) {
				hasil=tengah;
				break;
			}
			if (sel>b) { 
				kiri=tengah+1;
			} else kanan=tengah-1;
		}
		cout<<cwhkeuang(min(hasil,c-hasil))<<endl;
		scanf("%lld%lld",&a,&b);
	}
	
}
