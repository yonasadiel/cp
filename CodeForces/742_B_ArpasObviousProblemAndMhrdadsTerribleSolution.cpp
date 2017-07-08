#include<bits/stdc++.h>
using namespace std;

int arr[100005];
long long brr[400005];
bool sudah[400005];
int n,m;

int main() {
	memset(brr,0,sizeof brr);
	memset(sudah,false,sizeof sudah);
	
	scanf("%d%d",&n,&m);
	for (int i=0; i<n; i++) {
		scanf("%d",&arr[i]);
		brr[arr[i]]++;
	}
	
	long long ret = 0;
	for (int i=0; i<n; i++) {
		if (!sudah[arr[i]]){
			if (arr[i] == (m^arr[i])) {
				ret+=(long long)brr[arr[i]]* (long long)(brr[m^arr[i]]-1) /2;
				sudah[arr[i]] = true;
			} else {
				ret+=(long long)brr[arr[i]]* (long long)brr[m^arr[i]];
				sudah[arr[i]] = true;
				sudah[m^arr[i]] = true;	
			}
			
		}	
	}
	printf("%I64d\n",ret);
}
