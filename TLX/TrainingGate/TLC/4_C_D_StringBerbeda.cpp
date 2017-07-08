#include<bits/stdc++.h>
using namespace std;

int bedanya(string a, string b) {
//	cout<<a<<" "<<b<<endl;
	int hitung=0;
	for (int i=0; i<a.length(); i++) {
		if (a[i]!=b[i]) {
			hitung++;
		}
	}
	return hitung;
}

int main() {
	int hasil=999999999;
	string panjang,pendek;
	cin>>panjang>>pendek;
	if (panjang.length()<pendek.length()) {
		string temp=pendek;
		pendek=panjang;
		panjang=temp;
	}
	int beda=panjang.length()-pendek.length();

	for (int i=0; i<=beda; i++) {
//		cout<<panjang<<" "<<pendek<<endl;
		string baru="";
		for (int j=0; j<pendek.length(); j++) {
			baru+=panjang[j+i];
		}
		hasil=min(hasil,bedanya(baru,pendek));
	}
	cout<<hasil<<endl;
}
