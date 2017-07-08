#include<bits/stdc++.h>
using namespace std;

int t,n;
int ar[100005];

long long pangkat(int a, int b) {
	if (b==1) return a;
	if (b==0) return 1;
	return pangkat(a,b/2)*pangkat(a,b-b/2);
}

bool komp(int a, int b) {
	return pangkat(a,b) < pangkat(b,a);
}

int main() {
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		for (int i=0; i<n; i++) {
			scanf("%d",&ar[i]);
		}
		sort(ar,ar+n,komp);
		for (int i=0; i<n-1; i++) {
			printf("%d ",ar[i]);
		}
		printf("%d\n",ar[n-1]);
	}
}
