#include<bits/stdc++.H>
using namespace std;

long long fctr[1000005];
int j = 0;
int t;

int main() {
	long long n;
	scanf("%I64d%d",&n,&t);
	for (int i=1; i<=sqrt(n); i++) {
		if (n%i == 0) {
			fctr[j++] = i;
		}
	}
	for (int i=j-1; i>=0; i--) {
		if (i == j-1 && ((long long) sqrt(n) * sqrt(n) == n)) {
			continue;
		} else {
			fctr[j++] = n / fctr[i];
		}
	}
	/*
	for (int i=0; i<j; i++) {
		printf("%d ",fctr[i]);
	}
	*/
	
	if (t > j) {
		printf("-1\n");
	} else {
		printf("%I64d\n",fctr[t-1]);
	}
}
