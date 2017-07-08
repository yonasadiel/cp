#include<bits/stdc++.h>
using namespace std;

void play(long long n) {
	int ret=1;
	while (n>0) {
		if (n%2==0) ret++;
		else break;
		n/=2;
	}
	printf("%d\n",ret);
}

int main() {
	long long n;
	scanf("%I64d%I64d",&n,&n);
//	for (n=1; n<=1000; n++) {
//		printf ("%d ",n);
		play(n);
//	}
}
