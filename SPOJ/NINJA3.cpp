#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	long long n,a,b,t;
	scanf("%lld",&t);
	while(t--) {
		scanf("%lld%lld%lld",&n,&a,&b);
		long long le = __gcd(a,b);
		for (long long i=0; i<le; i++) {
			printf("%lld\n", n);
		}
		printf("\n");
	}
}
