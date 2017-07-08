#include<bits/stdc++.h>
using namespace std;

int main() {
	char kalimat[250];
	bool perdana=false;
	while(scanf("%s",kalimat)!=EOF){
		bool cek=true;
		int panjang=strlen(kalimat);
		for (int i=0; i<panjang/2; i++) {
			if (kalimat[i]!=kalimat[panjang-i-1]) {
				cek=false; break;
			}
		}
		if (perdana&&cek) printf(" ");
		perdana=true;
		if (cek) printf("%s",kalimat);
	}
	printf("\n");
}
