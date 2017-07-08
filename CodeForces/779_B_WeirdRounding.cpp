#include<bits/stdc++.h>
using namespace std;

int n,k;
int ret = 0;
int del = 0;

int main() {
	scanf("%d%d",&n,&k);
	if (n == 0) {
		printf("0\n");
		return 0;
	}
	for (int c = n; c > 0; c/=10) {
		del++;
	}
	while (k > 0) {
		if (n%10 != 0) {
			ret++;
		} else {
			k--;
		}
		n /= 10;
		if (n == 0 && k != 0) {
			printf("%d\n",del-1);
			return 0;
		}
	}
	printf("%d\n",ret);
}