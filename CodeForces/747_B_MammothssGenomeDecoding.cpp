#include<bits/stdc++.h>
using namespace std;

int n;
string sinp;

int main() {
	scanf("%d",&n);
	cin>>sinp;
	if (n%4!=0) {
		printf("===\n");
		return 0;
	} else {
		int occ[200];
		memset(occ,0,sizeof occ);
		for (int i=0; i<n; i++) {
			occ[sinp[i]]++;
			if (occ[sinp[i]] > n/4 && sinp[i]!='?') {
				printf("===\n");
				return 0;
			}
		}
		char na[4] = {'A','C','G','T'};
		int j=0;
		for (int i=0; i<n; i++) {
			if (sinp[i] == '?') {
				while (occ[na[j]] == n/4) {
					j++;
				}
				sinp[i] = na[j];
				occ[na[j]]++;
			}
		}
		cout<<sinp<<endl;
		
	}
}
