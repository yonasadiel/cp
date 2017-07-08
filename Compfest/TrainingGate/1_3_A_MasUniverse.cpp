#include <cstdio>
using namespace std;

int main() {
	int n,a,b=0;
	scanf("%d",&n);
	for (int i=0; i<n; i++) {
		scanf("%d",&a);
		if (a>b) b = a;
	}
	printf("%d\n",b);
}