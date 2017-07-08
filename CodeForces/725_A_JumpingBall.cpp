#include<bits/stdc++.h>
using namespace std;

int main() {
	char a[200005];
	int n;
	
	scanf("%d",&n);
	for (int i=0; i<=n; i++) {
		scanf("%c",&a[i]);
	}
	int ret=0;
	for (int i=1; i<=n; i++) {
		if(a[i]=='<') {
			ret++;
		} else {
			break;
		}
	}
	for (int i=n; i>0; i--) {
		if(a[i]=='>') {
			ret++;
		} else {
			break;
		}
	}
	printf("%d\n",ret);
}
