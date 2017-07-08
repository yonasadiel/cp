#define MOD 10007
#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	int ar[100005];
	
	scanf("%d",&n);
	for (int i=0; i<n; i++) {
		scanf("%d",&ar[i]);
	}
	
	sort(ar,ar+n);
	
	int hasil = 0;
	for (int i=0; i<n; i++) {
		hasil+=(ar[i]%MOD * ar[n-i-1]%MOD )%MOD;
		hasil%=MOD;
	}
	
	printf("%d\n",hasil);
}
