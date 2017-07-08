#include<bits/stdc++.h>
using namespace std;

int main() {
	long long a,b,c,maks;
	scanf("%I64d%I64d%I64d",&a,&b,&c);
	maks=max(a,max(b,c));
	long long ret=3*maks-2;
	if ((maks==a && maks==b)||(maks==b&&maks==c)||(maks==a&&maks==c))  ret++;
	if (maks==a&&maks==b&&maks==c) ret++;
	printf("%I64d\n",ret-a-b-c);
}
