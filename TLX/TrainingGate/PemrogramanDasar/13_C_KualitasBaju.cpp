#include<bits/stdc++.h>
using namespace std;

int n;
int arr[100005];

int main() {
	scanf("%d",&n);
	for (int i=0; i<n; i++) {
		scanf("%d",&arr[i]);
	}
	sort(arr,arr+n);
	printf("%.1f\n",n%2==0? (float) (arr[n/2]+arr[n/2-1])/2 : (float) arr[n/2]);
}
