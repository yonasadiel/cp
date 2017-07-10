#include <bits/stdc++.h>

int kali(int x) {
	if (x==0) return 1;
	if (x==1) return 1;
	return x*kali(x-1);
}

int main() {
	
	int n;
	scanf("%d",&n);
	if ((n<0) || (n>10)) {
		printf("ditolak\n");
		return 0;
	}
	printf("%d\n",kali(n));
	
	
	return 0;
}
