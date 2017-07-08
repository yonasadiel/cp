#include<bits/stdc++.h>
using namespace std;

int main() {
	int kase;
	scanf("%d",&kase);
	for (int k=1; k<=kase; k++) {
		int jumlah,sudah=0,lampu=0;
		string ladang;
//		cout<<"jumlah ditanya"<<endl;
		scanf("%d\n",&jumlah);
//		cout<<"jumlah diterima"<<endl;
		getline(cin,ladang);
		for(int i=0; i<jumlah; i++) {
			if (sudah==1) {
				sudah++;
				continue;
			}
			if (sudah==2) {
				sudah=0;
				continue;
			}
			if (ladang[i]=='.') {
				sudah=1;
				lampu++;
			}
		}
		printf("Case %d: %d\n",k,lampu);
	}
}
