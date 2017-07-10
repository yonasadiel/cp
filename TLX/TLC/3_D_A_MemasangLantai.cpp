#include<bits/stdc++.h>
using namespace std;

int main() {
	int kotak[1005];
	kotak[1]=1;
	kotak[2]=1;
	kotak[3]=2;
	for (int i=4; i<=1004; i++) {
		kotak[i]=(kotak[i-1]+kotak[i-3])%1000000;
	}
	int n;
	scanf("%d",&n);
	printf("%d\n",kotak[n]);
}
