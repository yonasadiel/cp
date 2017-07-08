#include <cstdio>
using namespace std;

int arr[105][105];

int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			scanf("%d",&arr[i][j]);
		}
	}
	for (int j=0; j<m; j++) {
		for (int i=0; i<n; i++) {
			if (i!=0) printf(" ");
			printf("%d",arr[i][j]);
		}
		printf("\n");
	}
}