#include<bits/stdc++.h>
using namespace std;

int n;
int arr[200005];

int main() {
	scanf("%d",&n);
	for(int i=0; i<n; i++) {
		scanf("%d",&arr[i]); 
	}
	for (int i=0; i<n/2; i+=2) {
		swap(arr[i],arr[n-i-1]);
	}
	printf("%d",arr[0]);
	for(int i=1; i<n; i++) {
		printf(" %d",arr[i]); 
	}
	printf("\n");
}
