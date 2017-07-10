#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d",&n);
	int mask =1;
	while(mask*2<=n) mask*=2;
	while (mask>0) {
		if (n>=mask) {
			printf("1");
			n-=mask;
		} else {
			printf("0");
		}
		mask/=2;
	}
	printf("\n");
}
