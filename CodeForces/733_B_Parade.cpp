#include<bits/stdc++.h>
using namespace std;

int main() {
	int n,l[100005],r[100005];
	long long L=0,R=0;
	scanf("%d",&n);
	for (int i=0; i<n; i++) {
		scanf("%d%d",&l[i],&r[i]);
		L += l[i];
		R += r[i];
	}
	
	long long maks=abs(L-R),ret=-1;
	for (int i=0; i<n; i++) {
		long long ln = L - l[i] + r[i];
		long long rn = R + l[i] - r[i];
		if (abs(ln-rn) > maks) {
			maks = abs(ln-rn);
			ret = i;
		}
	}
	
	printf("%d\n",++ret);
}
