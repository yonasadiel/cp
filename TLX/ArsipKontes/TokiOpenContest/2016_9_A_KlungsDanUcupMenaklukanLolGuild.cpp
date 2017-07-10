#include<bits/stdc++.h>
using namespace std;

int n,k,m;
char petak[1005];
int a;
vector <int> arr;
long long ret=0;

bool komp(int a,int b) {
	return a>b;
}

int main() {	
	scanf("%d%d%d%c",&n,&k,&m,&petak[0]);
	for (int i=0; i<n; i++) {
		scanf("%c",&petak[i]);
	}
	for (int i=0; i<n; i++) {
		scanf("%d",&a);
		if (petak[i]=='1') {
			arr.push_back(a);
		}
	}
	
	sort(arr.begin(),arr.end(),komp);
	
	for(int i=k; i<arr.size(); i++) {
		if (i<m+k) ret+=(arr[i]/2);
		else ret+=arr[i];
	}
	printf("%lld\n",ret);
}
