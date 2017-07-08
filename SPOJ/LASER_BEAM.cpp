#include<bits/stdc++.h>
using namespace std;

int t;
long long n,m;

long long gcd (long long a, long long b) {
//	cout<<"gcd("<<a<<","<<b<<");"<<endl;
	if (a<b) swap(a,b);
	if (b==0) return a;
	return gcd(b,a%b);
}

int main() {
	scanf("%d",&t);
	while(t--) {
		scanf("%lld%lld",&n,&m);
		m--; n--;
		printf("%lld\n",gcd(n,m)+1);
	}
}
