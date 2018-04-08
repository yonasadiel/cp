#include <cstdio>
using namespace std;

unsigned long long n, c, p;
unsigned long long ans = 0;

int main() {
	scanf("%I64d", &n);
	n--;
	c = 1;
	p = 1;
	while (n>0) {
		if (n&1)
			ans += c;
		c = p + (c<<1);
		p <<= 1;
		n >>= 1;
	}
	printf("%I64d\n", ans);
}