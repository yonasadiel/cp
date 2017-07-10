#include <bits/stdc++.h>

int main() {
	
	int i,bil,jum=0;
	scanf("%d",&i);

	for (int d=0;d<i;d++) {
		scanf("%d",&bil);
		jum+=bil;
	}
	printf("%d\n",jum);
	
	return 0;
}
