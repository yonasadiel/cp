#include<bits/stdc++.h>
using namespace std;

long long ret=0;
string sinp;

int main() {
	int n;
	scanf("%d",&n);
	for (int i=0; i<n; i++) {
		cin>>sinp;
		for (int j=0; j<sinp.length(); j++) {
			if (sinp[j] == 'A') ret+=4;
			if (sinp[j] == 'K') ret+=3;
			if (sinp[j] == 'Q') ret+=2;
			if (sinp[j] == 'J') ret+=1;
		}
	}
	printf("%lld\n",ret);
}
