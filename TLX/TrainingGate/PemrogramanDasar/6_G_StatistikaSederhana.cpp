#include<bits/stdc++.h>
using namespace std;

int main () {
	int n,ar[100005],maks=-99999999,mini=9999999;
	scanf("%d",&n);
	for (int i=0; i<n; i++) {
		scanf("%d",&ar[i]);
		maks=max(maks,ar[i]);
		mini=min(mini,ar[i]);
	}
	printf("%d %d\n",maks,mini);
	
	
}
