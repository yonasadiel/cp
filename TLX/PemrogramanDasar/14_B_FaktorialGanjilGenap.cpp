#include<bits/stdc++.h>
using namespace std;

long long f(int n) {
	if (n == 1) {
		return 1;
	} else if (n%2==0) {
		return (long long) n/2 *f(n-1);
	} else {
		return (long long) n*f(n-1);
	}
}

int main() {
	int n;
	scanf("%d",&n);
	printf("%lld\n",f(n));
}
