#include<bits/stdc++.h>
using namespace std;

bool check(int a) {
	int arr[10];
	memset(arr,0,sizeof arr);
	while (a>0) {
		if (arr[a%10] > 0) return false;
		else arr[a%10]++;
		a/=10;
	}
	return true;
}

int main() {
	int n;
	scanf("%d",&n);
	n++;
	while (1) {
		if (check(n)) {
			cout<< n;
			break;
		}
		n++;
	}
	
}
