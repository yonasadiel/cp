#include<bits/stdc++.h>
using namespace std;

int main() {
	long long n,ret=1,temp;
	scanf("%lld",&n);
	for (int i=0; i<n; i++) {
		scanf("%lld",&temp);
		ret = ret / __gcd(ret,temp) * temp;
	}
	printf("%lld\n",ret);
}
