#include<bits/stdc++.h>
using namespace std;

string angka;
int k,n;

void ganti(int i, int j) {
//	cout<<i<<" "<<j<<endl;
	char temp=angka[j];
	for (int l=j; l>i; l--) {
		angka[l]=angka[l-1];
	}
	angka[i]=temp;
	k-=(j-i);
}

int main() {
	cin>>angka>>k;
	n=angka.length();
	for (int i=0; i<n; i++) {
		int satu=i,dua=i;
		char minimum=angka[i];
		for (int j=i+1; j<n; j++) {
			if (angka[j]>minimum && j-i<=k) {
				dua=j;
				minimum=angka[j];
			}
		}
		ganti(satu,dua);
	}
	cout<<angka<<endl;
}
