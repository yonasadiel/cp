#include <bits/stdc++.h>
using namespace std;


int main() {
	
	int jumlah, noda[100005],maksi;
	memset(noda,0,sizeof (noda));
	scanf("%d",&jumlah);
	
	for (int a=0; a<jumlah; a++) {
		int masuk;
		scanf("%d",&masuk);
		noda[masuk]++;		
	}
	
	maksi=0;
	for (int a=0; a<100005; a++) {
		
		if (noda[a]>=noda[maksi]) {
			maksi=a;
		}
	}
	
	printf("%d\n",maksi);
	return 0;
}
