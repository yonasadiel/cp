#include<bits/stdc++.h>
using namespace std;

int n;

int main() {
	scanf("%d",&n);
	
	int maks = -1;
	int baru, streak = 0, lama = 1e9;
	for (int i=0; i<n; i++) {
		scanf("%d",&baru);
		if (baru < lama) {
			lama = baru;
			maks = max (streak,maks);
			streak = 0;
		} else {
			lama = baru;
			streak++;
		}
	}
	maks = max(maks,streak);
	
	printf("%d\n",maks+1);
}
