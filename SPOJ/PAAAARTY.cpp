#include<bits/stdc++.h>
using namespace std;

char petak[5][5];

string ubah(int a) {
	if (a==0) return "N";
	if (a==1) return "R";
	if (a==2) return "B";
	if (a==3) return "G";
}

char konversi(char a, char b) {
	if (a=='N') return b;
	if (b=='N') return a;
	if (a==b) return 'N';
	if (a=='R') {
		if (b=='G') return 'B';
		if (b=='B') return 'G';
	}
	if (a=='G') {
		if (b=='R') return 'B';
		if (b=='B') return 'R';
	}
	if (a=='B') {
		if (b=='G') return 'R';
		if (b=='R') return 'G';
	}
}

bool cek(string a) {
	for (int i=0; i<a.length(); i++) {
		if (a[i]!='N') return false;
	}
	return true;
}

void jalan(int a,int b,int c,int d, int e) {
	
	string kalimat="";
	kalimat+=ubah(a)+ubah(b)+ubah(c)+ubah(d)+ubah(e);
	cout<<kalimat<<" ";
	string beku=kalimat;
	int J=0;
	while(!cek(kalimat) && J<140) {
		char last=kalimat[0];
		for (int i=0; i<kalimat.length()-1; i++) {
			kalimat[i]=konversi(kalimat[i],kalimat[i+1]);
		}
		kalimat[kalimat.length()-1]=konversi(kalimat[kalimat.length()-1],last);
		J++;
	}
	if (cek(kalimat)) {
		cout<<J<<endl;
/*		kalimat=beku;
		while(!cek(kalimat) && J<140) {
			char last=kalimat[0];
			for (int i=0; i<kalimat.length()-1; i++) {
				kalimat[i]=konversi(kalimat[i],kalimat[i+1]);
			}
			kalimat[kalimat.length()-1]=konversi(kalimat[kalimat.length()-1],last);
			J++;
			cout<<kalimat<<endl;
		}*/
	} else {
		cout<<"Party!"<<endl;
	}

}
int main() {
	for (int i=0; i<4; i++) {
		for (int j=0; j<4; j++) {
			for (int k=0; k<4; k++) {
				for (int l=0; l<4; l++) {
					for (int m=0; m<4; m++) {
						jalan(i,j,k,l,m);	
					}
					
				}
			}
		}
	}	
}
