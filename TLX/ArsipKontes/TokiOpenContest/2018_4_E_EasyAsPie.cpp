#include <cstdio>
#define ll long long
#define MOD 1000000007
using namespace std;

int main() {
	ll a, b;
	scanf("%lld%lld", &a,&b);
	printf("%lld\n", (a*b)%(10^9+7));
}