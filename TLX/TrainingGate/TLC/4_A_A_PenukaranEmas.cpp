#include<bits/stdc++.h>
using namespace std;
//int barang;

int cari(int mula) {
	int sesudah=mula/2+mula/3+mula/4;
//	cout<<mula/2<<" "<<mula/3<<" "<<mula/4<<endl;
//	scanf("%d",&barang);
	if (sesudah<=mula) return mula;
	return cari(mula/2)+cari(mula/3)+cari(mula/4);
}

int main() {
	int n,a,b;
//	cout<<"haha"<<endl;
//while(true) {
	
	scanf("%d",&a);
//	if (a==-1) return 0;
//	cout<<"hh"<<endl;
	a=cari(a);
	printf("%d\n", a);
	
//}
}
