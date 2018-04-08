#include <cstdio>
using namespace std;

int main() {
	int n;
	scanf("%d",&n);
	if (n >= 6) {
		for (int i=2; i<=n; i+=2) {
			printf("1 %d\n", i);
			if (i < n) printf("2 %d\n", i+1);
		}
	} else {
		printf("-1\n");
	}
	for (int i=2; i<=n; i++) {
		printf("1 %d\n", i);
	}
}