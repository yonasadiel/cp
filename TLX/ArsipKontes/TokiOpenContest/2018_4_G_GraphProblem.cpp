#include <cstdio>
using namespace std;

int main() {
	int n, ans=0;
	scanf("%d", &n);
	for (int i=0; i<=n; i++) {
		ans = ans ^ i;
	}
	printf("%d\n", ans);
}