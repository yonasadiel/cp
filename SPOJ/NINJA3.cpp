#include<bits/stdc++.h>
using namespace std;

long long gcd(long long a,long long b) {
	if (b==0) return a;
	return gcd(b,a%b);
}

int main() {
	long long n,a,b,t;
	cin>>t;
	while(t--) {
		cin>>n>>a>>b;
		if (a<b) swap(a,b);
		long long le=gcd(a,b);
		for (long long i=0; i<le; i++) {
			cout<<n;
		}
		cout<<endl;
	}
}
