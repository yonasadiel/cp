#include<bits/stdc++.h>
using namespace std;

int main() {
	int a,b,c,as,ae,harga=0,jumlah[105];
	memset(jumlah,0,sizeof jumlah);
	scanf("%d %d %d",&a,&b,&c);
	scanf("%d %d",&as,&ae);
	for (int i=as;i<ae;i++) {
		jumlah[i]++;
	}
	scanf("%d %d",&as,&ae);
	for (int i=as;i<ae;i++) {
		jumlah[i]++;
	}
	scanf("%d %d",&as,&ae);
	for (int i=as;i<ae;i++) {
		jumlah[i]++;
	}
	for (int i=1; i<=100; i++) {
		if (jumlah[i]==1) harga+=a;
		if (jumlah[i]==2) harga+=b*2;
		if (jumlah[i]==3) harga+=c*3;
	}
	printf("%d\n",harga);
}
