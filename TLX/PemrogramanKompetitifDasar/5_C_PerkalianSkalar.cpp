#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int arr[10005];
int brr[10005];

bool cmp(int le, int ri) {
	return le > ri;
}

int main() {
	scanf("%d",&n);
	for (int i=0; i<n; i++) { scanf("%d",&arr[i]); }
	for (int i=0; i<n; i++) { scanf("%d",&brr[i]); }
	sort(arr, arr+n);
	sort(brr, brr+n,cmp);
	long long ret = 0;
	for (int i=0; i<n; i++) {
		ret += (long long) ((long long) arr[i] * (long long) brr[i]);
	}
	printf("%lld\n", ret);
}