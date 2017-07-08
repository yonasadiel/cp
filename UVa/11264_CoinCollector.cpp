#include<bits/stdc++.h>
using namespace std;

int main() {
	long long kase,n,arr[1005];
	scanf("%lld",&kase);
	while (kase--) {
		scanf("%d",&n);
		for(int i = 0; i < n; i++) scanf("%lld",&arr[i]);
		long long bisa=0,sementara,total=0; arr[n] = 2e9;
		for (int i=0; i<n; i++) {
			sementara = arr[i];
			if (total + sementara < arr[i + 1]) {
				bisa++;
				total+=sementara;
//				cout<< sementara << "<=" << total << endl;
			}
		}
//		if (bisa!=n) bisa++;
		printf("%lld\n",bisa);
	}
}
