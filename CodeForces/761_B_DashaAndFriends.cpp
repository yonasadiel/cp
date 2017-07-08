#include<bits/stdc++.h>
using namespace std;

int arr[100];
int brr[100];

int main() {
	int n,l,x;
	memset(arr,0,sizeof arr);
	scanf("%d%d",&n,&l);
	for (int i=0; i<n; i++) {
		scanf("%d",&x);
		arr[x] = 1;
	}
	for (int i=0; i<n; i++) {
		scanf("%d",&brr[i]);
	}
	bool fnd = false;
	for(int i=0; i<l; i++) {
		bool fndt = true;
		for (int j=0; j<n; j++) {
			if (arr[(brr[j]+i)%l] == 0) {
				fndt = false;
			}
		}
		if (fndt) {
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
	return 0;
	
}
