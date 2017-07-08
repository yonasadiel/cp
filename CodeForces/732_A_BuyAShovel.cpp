#include<bits/stdc++.h>
using namespace std;

int main() {
	int n,k;
	scanf("%d%d",&n,&k);
	int cnt=1,a=n;
	while(a%10!=k && a%10 != 0) {
		cnt++;
		a+=n;
	}
	printf("%d\n",cnt);
}
