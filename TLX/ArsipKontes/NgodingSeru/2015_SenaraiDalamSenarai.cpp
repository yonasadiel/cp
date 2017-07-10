#include<bits/stdc++.h>
using namespace std;

string masukan;

int main() {
	int kasus; 
	scanf("%d",&kasus);
	while (kasus--) {
		int tingkat;
		scanf("%d\n",&tingkat);
		cin>>masukan;
		int panjang=masukan.length();
		int tingkat_sementara=0;
		int hitung=0;
		for (int i=0; i<panjang; i++) {
			if (masukan[i]=='[') {
				tingkat_sementara++;
				if (tingkat_sementara==tingkat) {
					hitung++;
				}
			}
			if (masukan[i]==']') {
				tingkat_sementara--;
			}
		}
		cout<<hitung<<endl;
		tingkat_sementara=0;
		for (int i=0; i<panjang; i++) {
			if (masukan[i]=='[') {
				tingkat_sementara++;
			}
			if (tingkat_sementara>=tingkat) {
				cout<<masukan[i];
			}
			if (masukan[i]==']') {
				if (tingkat_sementara==tingkat) {
					cout<<endl;	
				}
				tingkat_sementara--;
			}
		}
	}
}
