#include<bits/stdc++.h>
using namespace std;

int a,b,x;

int f(int k) {
	if (k==0) return x;
	return abs(a*f(k-1)+b);
}

int main() {
	int k;
	scanf("%d%d%d%d",&a,&b,&k,&x);
	printf("%d\n",f(k));
}
