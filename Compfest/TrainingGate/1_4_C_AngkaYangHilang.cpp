#include <cstdio>
#include <cstring>
using namespace std;

int toogle[100005];

int main() {
	int n,k;
	memset(toogle,0,sizeof toogle);
	scanf("%d%d",&n,&k);
	for (int i=0; i<k; i++) {
		int b;
		scanf("%d",&b);
		toogle[b] = 1;
	}
	bool ck = false;
	for (int i=1; i<=n; i++) {
		if (toogle[i] == 0) {
			if (ck) { printf(" "); }
			printf("%d",i);
			ck = true;
		}
	}
	printf("\n");
}