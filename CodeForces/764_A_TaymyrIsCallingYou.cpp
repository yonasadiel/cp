#include<bits/stdc++.h>
using namespace std;

/***** GREATEST COMMON DIVISOR **************************/
// return the gcd of a and b
// complexity: log a + log b
#define ll long long

ll gcd(ll a, ll b) {
	if (a == 0) return b;
	return gcd(b%a,a);
	return __gcd(a,b); // built-in gcd
}

/***** LEAST COMMON MULTIPLE OF TWO LONG LONG ***********/
// return the lcm of a and b
// complexity: ???
#define ll long long

ll lcmOfTwo(ll a, ll b) {
	return a/__gcd(a,b)*b;
}

int main() {
	int n,a,b;
	scanf("%d%d%d",&n,&a,&b);
	printf("%d\n",b/lcmOfTwo(n,a));
}
