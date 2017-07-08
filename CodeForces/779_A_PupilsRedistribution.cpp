#include<bits/stdc++.h>
using namespace std;

int n;
int arr[10],brr[10];
int in;

int main() {
	scanf("%d",&n);
	for (int i=0; i<n; i++) {
		scanf("%d",&in);
		arr[in]++;
	}
	for (int i=0; i<n; i++) {
		scanf("%d",&in);
		brr[in]++;
	}

	int ret = 0;
	for (int i=1; i<6; i++) {
		if (abs(arr[i] - brr[i])%2 != 0) {
			printf("-1\n");
			return 0;
		} else {
			ret += abs(arr[i] - brr[i])/2;
		}
	}
	printf("%d\n",ret/2);
}