#include<bits/stdc++.h>
using namespace std;

int main() {
	int t,n;
	scanf("%d",&t);
	while(t--) {
		unsigned long long hasil=0;
		scanf("%d",&n);
		long long ret=(n+2)*(n+1)*n/6;
		if (n%2==0) {
			ret+=n*(n+2)*(2*n-1)/24;
		} else {
			ret+=(n*n-1)*(2*n+3)/24;
		}
		printf("%llu\n",ret);
	}
}
