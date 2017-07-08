#include<bits/stdc++.h>
using namespace std;

int main() {
	int a,b,k,x,ret;
	scanf("%d%d%d%d",&a,&b,&k,&x);
	ret=x;
	while (k--) {
		ret=abs(a*ret+b);
	}
	printf("%d\n",ret);
}
