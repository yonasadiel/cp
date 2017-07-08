#include<bits/stdc++.h>
using namespace std;

int main() {
	int n,k,dump,lolos = 0,batas;
	scanf("%d%d",&n,&k);
	for (int i=0; i<n; i++) {
		scanf("%d",&dump);
		if (i==k-1) {
			batas = dump;
			lolos = k;
		}
		if (i>=k) {
			if (dump == batas) {
				lolos++;
			} else {
				break;
			}
		}
		if (dump == 0) {
			lolos = i;
			break;
		}
	}
	printf("%d\n",lolos);
}
