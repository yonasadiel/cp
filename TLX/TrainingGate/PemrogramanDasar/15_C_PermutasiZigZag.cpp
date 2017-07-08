#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	bool sebelum, sesudah;
	int arr[10]={1,2,3,4,5,6,7,8,9,10};
	scanf("%d",&n);
	do {
		bool benar=true;
		if (arr[1]>arr[0]) {
			sebelum=true;
		}
		if (arr[1]<arr[0]) {
			sebelum=false;
		}
		for (int i=2; i<n; i++) {
			if (arr[i]>arr[i-1]) {
				sesudah=true;
			} else {
				sesudah=false;
			}
			if (sesudah^sebelum) {
				sebelum=sesudah;
			} else {
//			printf("haha");
				benar=false;
				break;
			}
		}
		if (benar) {
			for (int i=0; i<n-1; i++) {
				printf("%d",arr[i]);
			}
			printf("%d\n",arr[n-1]);
		}
	} while(next_permutation(arr,arr+n));
}
