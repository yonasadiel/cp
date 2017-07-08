#include <cstdio>
using namespace std;

int g(int n) {
	int ret = 0;
	for (int i=1; i<=n; i++) {
		if (n%i == 0) {
			ret++;
		}
	}
	return ret;
}

int h(int n) {
	int ret = 0;
	for (int i=1; i<=n; i++) {
		ret += g(i);
	}
	return ret;
}

int main() {
	int n;
	scanf("%d",&n);
	printf("%d\n",h(n));
}