#include <cstdio>
using namespace std;

int main() {
	int n,a,b = 0;
	scanf("%d",&n);
	for (int i=0; i<n; i++) {
	for (int j=0; j<n; j++) {
		scanf("%d",&a);
		if (i==j) b += a;
	}
	}
	printf("%d\n",b);
}