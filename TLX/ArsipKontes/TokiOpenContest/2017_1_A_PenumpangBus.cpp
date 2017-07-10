#include<bits/stdc++.h>
#define fi first
#define se second
#define mp(a,b) make_pair(a,b)
using namespace std;

stack<int> pe;

int main() {
	int n,m,k,maks=-1;
	scanf("%d",&n);
	for (int i=0; i<n; i++) {
		scanf("%d%d",&m,&k);
		for (int j =0; j<k; j++) {
			maks = max(maks,i-pe.top());
			pe.pop();
		}
		for (int j =0; j<m; j++) {
			pe.push(i);
		}
	}
	while(!pe.empty()) {
		maks=max(maks,n-pe.top()-1);
		pe.pop();
	}
	printf("%d\n",maks*10);
}
