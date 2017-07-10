#include<bits/stdc++.h>
using namespace std;

int main() {
	int n,x,a,last=0;
	int arr[1005];
	scanf("%d%d",&n,&x);
	for (int i=0;i<n; i++) {
		scanf("%d",&arr[i]);
	}
	sort(arr,arr+n);
	for (int i=0; i<n; i++) {
		if (abs(arr[i]-x) < abs(arr[last]-x)) {
			last = i;
		}
	}
	printf("%d\n",arr[last]);
}
