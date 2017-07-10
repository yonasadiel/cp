#include<bits/stdc++.h>
using namespace std;

int jarak[100005];

int main() {
	int kasus; 
	scanf("%d",&kasus);
	for (int i=0; i<kasus; i++) {
		int n,h;
		scanf("%d%d",&n,&h);
		for (int j=0; j<n; j++) {
			scanf("%d",&jarak[j]);
		}
		sort(jarak,jarak+n);
		h-=jarak[n-1];
		int lompat=0;;
		int depan=0;
		int belakang=n-1;
		while (depan<=belakang) {
			int tengah=(depan+belakang)/2;
			if (jarak[tengah]>=h && jarak[tengah-1]<h) {
				lompat=jarak[tengah];
				break;
			} else if (jarak[tengah]>=h) {
				belakang=tengah-1;
			} else {
				depan=tengah+1;
			}		
		}
		cout<<jarak[n-1]+lompat<<endl;
	}
}
