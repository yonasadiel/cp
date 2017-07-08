#include<bits/stdc++.h>
using namespace std;

string kecilkan(string a) {
	string hasil="";
	for (int k=0; k<a.length(); k++) {
		if (a[k]<91 && a[k] > 50) {
			a[k]+=32;
		}
		hasil+=a[k];
	}
	return hasil;
}

int main() {
	int n;
	string kalimat[1005];
	string kalimatbaru;
	scanf("%d\n",&n);
	for (int i=0; i<n; i++) {
		getline(cin,kalimatbaru);
		kalimatbaru=kecilkan(kalimatbaru);
		kalimat[i]=kalimatbaru;
		sort(kalimat,kalimat+i+1);
		for (int j=0; j<=i; j++) {
			if (kalimat[j]==kalimatbaru) {
				printf("%d\n",j+1);
			}
		}
	}
}
