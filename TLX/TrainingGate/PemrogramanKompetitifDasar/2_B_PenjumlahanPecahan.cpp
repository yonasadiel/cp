#include<bits/stdc++.h>
using namespace std;

int main() {
	long long a,b,c,d,e,f,g;
	scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
	if (b==0  || d==0) while (1);
	f=b/__gcd(b,d)*d;
	e=f/b*a+f/d*c;
	
	long long h = __gcd(e,f);
	e/=h; f/=h;
	printf("%lld %lld\n",e,f);
	return 0;
}
