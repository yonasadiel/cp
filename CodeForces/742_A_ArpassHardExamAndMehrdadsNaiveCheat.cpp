#include<bits/stdc++.h>
using namespace std;

int arr[4] = {6,8,4,2};

int main() {
	int n;
	scanf("%d",&n);
	if (n==0) {
		printf("1\n");
		return 0;
	}
	printf("%d\n",arr[n%4]);
}
