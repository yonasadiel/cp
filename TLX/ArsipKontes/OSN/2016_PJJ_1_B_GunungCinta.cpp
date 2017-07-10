#define ll long long
#include<bits/stdc++.h>
using namespace std;
		
int main() {
	string subsoal;
	ll n;
	
	cin>>subsoal;
	scanf("%lld",&n);
	ll res=n/3+1;
	if (n&1) {
		res+=((n-1)/2)*((((n-1)/2)/3+1))+((((n-3)/2)/3+1))*((n-3)/2);
	} else {
		res+=(((n/2)/3+1))*((n)/2)+((((n-4)/2)/3+1))*((n-4)/2);
	}
	printf("%lld\n",res);
}
