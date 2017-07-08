#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, x;
	int arr[105];
	scanf("%d%d",&n,&x);
	for (int i=0; i<n; i++) {
		scanf("%d",&arr[i]);
	}
	sort(arr,arr+n);
	int cnt = 0;
	for (int i=0; i<n; i++) {
		if (x - arr[i] >= 0) {
			cnt++;
			x -= arr[i];
		} else {
			break;
		}
	}
	printf("%d\n",cnt);
}
