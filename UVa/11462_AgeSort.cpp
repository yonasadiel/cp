#include <cstdio>
#include <algorithm>
using namespace std;

int belum[2000000];

int main () {
	int n=1;

	while (n!=0 ){
 		scanf("%d",&n);
		if (n==0) return 0;

		for (int i=0;i<n;i++) {
			scanf("%d",&belum[i]);
		}
		
		sort(belum,belum+n);
		
		for (int i=0;i<n;i++) {
			if (i==n-1) {
				printf("%d",belum[i]); break;
			}
			printf("%d ",belum[i]);
		}
		
		printf("\n");
	}
}
