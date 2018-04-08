#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int arr[200];

long long fact(int x) {
	long long ans = 1;
	for (long long i=1; i<=x; i++) {
		ans *= i;
	}
	return ans;
}

int main() {
	scanf("%d",&n);
	for (int i=0; i<n; i++) {
		scanf("%d",&arr[i]);
	}
	sort(arr, arr+n);

	int ans = arr[1] - arr[0];
	for (int i=1; i<n; i++) {
		ans = min(ans, arr[i] - arr[i-1]);
	}
	printf("%lld\n", fact(ans));
}