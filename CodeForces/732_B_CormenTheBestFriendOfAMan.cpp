#include<bits/stdc++.h>
using namespace std;

int n,k;
int arr[505],brr[505],crr[505];
long long ret1=0,ret2=0;

int main() {
	scanf("%d%d",&n,&k);
	for (int i=0; i<n; i++) {
		scanf("%d",&arr[i]);
		brr[i]=arr[i];
		crr[i]=arr[i];
	}
	
	for (int i = 1; i<n; i++) {
		if (brr[i]+brr[i-1] < k) {
			ret1+=k - brr[i] - brr[i-1];
			brr[i] = k - brr[i-1];
		}
	}
	
	for (int i = 0; i<n-1; i++) {
		if (crr[i]+crr[i+1] < k) {
			ret2+=k - crr[i] - crr[i+1];
			crr[i] = k - crr[i+1];
		}
	}
	
	if (ret1 < ret2) {
		printf("%I64d\n%d",ret1,brr[0]);
		for (int i = 1; i<n; i++) {
			printf(" %d",brr[i]);
		}	
	} else {
		printf("%I64d\n%d",ret2,crr[0]);
		for (int i = 1; i<n; i++) {
			printf(" %d",crr[i]);
		}
	}
	
	
	
}
