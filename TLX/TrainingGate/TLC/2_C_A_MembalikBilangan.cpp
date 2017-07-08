#include<bits/stdc++.h>
using namespace std;

int main () {
	
	string kalimat;
	int c=0,jumlah;
	bool cek=true;
	
	scanf("%d\n",&jumlah);
	for (int i=1; i<=jumlah;i++) {
		cek=true;
		getline(cin,kalimat);
		for (int j=kalimat.length()-1; j>=0; j--) {
			if ((cek)&&(kalimat[j]=='0')&&j!=0) { continue;}
		 	printf("%c",kalimat[j]); cek=false;		
		}
		printf("\n");
	}
	

	
}
