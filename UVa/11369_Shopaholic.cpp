#include<bits/stdc++.h>
using namespace std;

int harga[1000000];

bool komp(int i, int j) {
	return(i>j);
}

int main () {
	int kase,total=0,jumlah;
	scanf("%d",&kase);
	while (kase--) {
		total=0;
		scanf("%d",&jumlah);
		for (int i=0; i<jumlah;i++) {
			scanf("%d",&harga[i]);
		}
		
		sort (harga,harga+jumlah,komp);
		
		for (int i=2; i<jumlah;i+=3) {
//			cout<<total<<endl;
			total+=harga[i];
		}
		printf("%d\n",total);
	}
} 
