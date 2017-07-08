#include <cstdio>
using namespace std;

int main() {
	int n,m,l;
	scanf("%d%d%d",&n,&m,&l);
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (j < l || i < l || n-i <= l) {
				printf("*");
			} else {
				printf(".");
			}
		}
		printf("\n");
	}
}