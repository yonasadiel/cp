#include <cstdio>
using namespace std;

int cnt[1005];

int main() {
	int n,m,x;
	scanf("%d%d",&n,&m);

	for (int i=0; i<n; i++) cnt[i] = 0;

	for (int i=0; i<m; i++) {
		scanf("%d",&x);
		cnt[x-1]++;
	}

	int minx = cnt[0];
	for (int i=1; i<n; i++) {
		if (cnt[i] < minx) minx = cnt[i];
	}
	printf("%d\n", minx);
}