#include<bits/stdc++.h>
using namespace std;

int main() {
	int t,n;
	priority_queue<int,vector<int>, greater<int> >antri;
	scanf("%d",&t);
	while (t--) {
		while(!antri.empty()) antri.pop();
		scanf("%d",&n);
		if(n==1) {
			printf("1\n");
			continue;
		}
		if(n==0) {
			printf("10\n");
			continue;
		}
		bool bisa=true;
		int last=n;
		while(n>1) {
			for (int j=9; j>=2; j--) {
				while (n%j==0) {
					n/=j;
					antri.push(j);
				}	
			}
			if (n==last) {
				bisa=false;
				break;
			}
			last=n;
		}
		if (!bisa) {
			printf("-1\n");
			continue;
		}
		while(bisa && !antri.empty()) {
			printf("%d",antri.top());
			antri.pop();
		}
		printf("\n");
	}
}
