#include<bits/stdc++.h>
using namespace std;

long long n;

int main() {
	while (true) {
		scanf("%d",&n);
		if (n==0) return 0;
		
		long long cnt;
		long long res=0;
		int temp;
		scanf("%lld",&cnt);
		for (int i=1; i<n; i++) {
			res+=abs(cnt);
			scanf("%d",&temp);
			cnt+=temp;
		}
		printf("%lld\n",res);
	}
	
}
