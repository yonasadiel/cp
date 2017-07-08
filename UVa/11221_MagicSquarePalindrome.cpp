#include<bits/stdc++.h>
using namespace std;

int n,panjangKalimat,panjangKalimatbaru,k;
string kalimat,kalimatfiks;

bool cekAwal() {
	return panjangKalimatbaru==(k*k);
}

bool cekSatu() {
	for (int i=0; i<panjangKalimatbaru/2+1; i++) {
		if (kalimatfiks[i]!=kalimatfiks[panjangKalimatbaru-i-1]){
			return false;
		}
	}
	return true;
}

bool cekDua() {
	for (int i=0; i<k/2+1; i++) {
		for (int j=0; j<k; j++) {
			if (kalimatfiks[j*k+i]!=kalimatfiks[panjangKalimatbaru-j*k-1-i]) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	scanf("%d\n",&n);
	for (int kase=0; kase<n; kase++) {
		kalimatfiks="";
		getline(cin,kalimat);
		panjangKalimat=kalimat.length();
		for (int i=0; i<panjangKalimat; i++) {
			if (kalimat[i]>64 && kalimat[i]<91 || kalimat[i]>96 && kalimat[i]<123) {
				kalimatfiks+=kalimat[i];
			}
		}
		panjangKalimatbaru=kalimatfiks.length();
		k=sqrt(panjangKalimatbaru);
//		cout<<kalimatfiks<<" "<<panjangKalimatbaru<<" "<<k*k<<endl;
		if (cekAwal() && cekSatu() && cekDua()) {
			printf("Case #%d:\n%d\n",kase+1,k);
		} else {
			printf("Case #%d:\nNo magic :(\n",kase+1);
		}
		
		
	}
}
