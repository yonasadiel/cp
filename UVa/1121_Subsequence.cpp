#include<bits/stdc++.h>
using namespace std;

int main() {
	int n,s,angka[100005];
	while(scanf("%d%d",&n,&s)!=EOF) {
		for (int i=0; i<n; i++) {
			scanf("%d",&angka[i]);
		}
		int head=0,tail=0,jumlah=0,minim=n+2;
		jumlah+=angka[head];
		while (head<n) {
			if (jumlah<s) {
				head++;
				jumlah+=angka[head];
			}
			if (jumlah>=s) {
				minim=min(minim,head-tail+1);
				jumlah-=angka[tail];
				tail++;
			}
		}
		if (minim==n+2) minim=0;
		printf("%d\n",minim);
	}
	
	return 0;
}
