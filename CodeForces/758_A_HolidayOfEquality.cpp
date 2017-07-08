#include<bits/stdc++.h>
using namespace std;

int n,arr[105],ma;

int main() {
	scanf("%d",&n);
	for (int i=0; i<n; i++) {
		scanf("%d",&arr[i]);
		ma = max(ma,arr[i]);
	}
	
	long long ret = 0;
	for (int i=0; i<n; i++) {
		ret+= (long long) ma-arr[i];
	}
	printf("%I64d\n",ret);
}
