#include<bits/stdc++.h>
using namespace std;

int main() {
	long long n,m,a;
	scanf("%I64d%I64d%I64d",&n,&m,&a);
	long long banyak=1;
	if (n%a==0) {
		banyak*=n/a;
	} else {
		banyak*=(n/a)+1;
	}
	if (m%a==0) {
		banyak*=m/a;
	} else {
		banyak*=(m/a)+1;
	}
	printf("%I64d\n",banyak);
}
