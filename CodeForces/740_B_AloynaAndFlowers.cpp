#include<bits/stdc++.h>
using namespace std;

int arr[1000],brr[1000];
long long ret = 0;

int main() {
	memset(brr,0,sizeof brr);
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=0; i<n; i++) {
		scanf("%d",&arr[i]);
	}
	for (int i=0; i<m; i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		for (int j=a-1; j<b; j++) {
			brr[i]+=arr[j];
		}
		if (brr[i] > 0) ret += (long long) brr[i];
	}
	printf("%I64d\n",ret);
	
}
