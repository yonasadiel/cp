#include<bits/stdc++.h>
using namespace std;

int main() {
	long long kali;
	scanf("%lld",&kali);
	while (kali--) {
		long long n,jumlah=0;
		scanf("%lld",&n);
		for (int k=1; k<=n; k++) {
			jumlah+=(k-1)*n+k;
		}
		printf("%lld\n",jumlah);
	}
	
}
