#include <cstdio>
#include <algorithm>
using namespace std;

int h[50000];

bool cmp(int a, int b) {
	return a>b;
}

int main() {
	int n,b;
	scanf("%d%d",&n,&b);
	for (int i=0; i<n; i++) {
		scanf("%d",&h[i]);
	}
	sort(h,h+n,cmp);
	int cnt = 0;
	while (b > 0) {
		if (cnt == n) {
			printf("-1\n");
			return 0;
		}
		b-=h[cnt++];
	}
	printf("%d\n",cnt);
}