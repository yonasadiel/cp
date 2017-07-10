#include<bits/stdc++.h>
using namespace std;

int main() {
	int a,b,c,k;
	scanf("%d%d%d%d",&a,&b,&c,&k);
	if (k==1) {
		if (a>b) {
			swap(a,b);
		}
		if (b>c) {
			swap(b,c);
		}
		if (a>b) {
			swap(a,b);
		}
	} else {
		if (a<b) {
			swap(a,b);
		}
		if (b<c) {
			swap(b,c);
		}
		if (a<b) {
			swap(a,b);
		}
	}
	printf("%d %d %d\n",a,b,c);
}
