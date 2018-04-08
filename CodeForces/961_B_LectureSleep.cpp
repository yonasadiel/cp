#include <cstdio>
#include <algorithm>
using namespace std;

int n,k;
int a[100005];
int b;
int c[100005];

int main() {
	int ans = 0;
	int temp;
	scanf("%d%d",&n,&k);
	for (int i=0; i<n; i++) {
		scanf("%d",&a[i]);
	}
	for (int i=0; i<n; i++) {
		scanf("%d",&b);
		if (b == 1) {
			ans += a[i];
			a[i] = 0;
		}
	}
	for (int i=0; i<n; i++) {
		if (i == 0) c[i] = a[i];
		else c[i] = c[i-1] + a[i];
	}
	temp = c[k-1];
	for (int i=k; i<n; i++) {
		temp = max(temp, c[i]-c[i-k]);
	}
	printf("%d\n", ans+temp);
}