#include <bits/stdc++.h>

int main() {
	
	int n;
	scanf("%d",&n);
	/*
	int i,maks;
	bool jawab[1000] = false;
	maks:=n;
	for (i=1;i<=maks;i++) {
		if (n%i == 0) {
			jawab[i]=true;
			jawab[n/i]=true;
			maks=n/i;
		}
	}
	for (i=1;i<=n;i++) {
		if jawab[i] {
			printf("%d\n",i);
		}
	}
	*/
	int i;
	for (i=n;i>=1;i--) {
		if (n%i == 0) {
			printf("%d\n",i);
		}
	}
	
	
	
	
	
	return 0;
}
