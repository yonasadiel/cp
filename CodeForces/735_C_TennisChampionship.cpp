#include<bits/stdc++.h>
using namespace std;

int main() {
//	while(1){
		long long a,b=2,c=1,d=1;
		scanf("%I64d",&a);
		if (a==1) d = 0;
		else while(1) {
			long long t = b; b=b+c; c=t;
			if (b>a || b<0) break;
			d++;
		}
		printf("%I64d\n",d);
//	}
}
