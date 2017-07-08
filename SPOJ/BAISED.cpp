#include<bits/stdc++.h>
using namespace std;

int t,n;
string dumb;
long long ar[100005];

int main() {
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		for (int i=0; i<n; i++) {
			cin>>dumb;
			scanf("%lld",&ar[i]);
		}
		sort(ar,ar+n);
		long long res=0;
		for(int i=0; i<n; i++) {
			res+=abs(ar[i]-i-1);
		}
		printf("%lld\n",res);
	}
}
