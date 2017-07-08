#include<bits/stdc++.h>
using namespace std;

int main() {
	long long n,a,b,c;
	scanf("%I64d%I64d%I64d%I64d",&n,&a,&b,&c);
	long long m = (n%4),ret;
	if (m==0) ret = 0;
	if (m==3) ret = min(a  ,min(b+c,c*3));
	if (m==2) ret = min(a*2,min(b  ,c*2));
	if (m==1) ret = min(a*3,min(a+b,c  ));
	printf("%I64d\n",ret);
}
