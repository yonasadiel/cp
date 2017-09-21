#include <cstdio>
#include <algorithm>
using namespace std;

int t;
long long n,m;

int main() {
	scanf("%d",&t);
	while(t--) {
		scanf("%lld%lld",&n,&m);
		m--; n--;
		printf("%lld\n",__gcd(n,m)+1);
	}
}
