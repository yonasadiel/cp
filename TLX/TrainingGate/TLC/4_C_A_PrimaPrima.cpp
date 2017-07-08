#include<bits/stdc++.h>
using namespace std;

bool prima[10005];

void cekprima(int kiri,int kanan) {
	memset(prima,true,sizeof prima);
	prima[1]=false;
	for (int i=2; i<=10005; i++) {
		if (prima[i]) {
			for (int j=2*i; j<=10005; j+=i) {
				prima[j]=false;
			}
		}
	}
}

bool periksa(int n) {
	int cek=2;
    while(cek<=sqrt(n)) {
    	if (n%cek==0) {
    		return false;
        }
        cek++;
    }
	return true;
}

int main() {
	int n,m;
	bool oke=true;
	scanf("%d%d",&n,&m);
	cekprima(n,m);
	
	for (int i=n; i<=m; i++) {
		for (int j=n; j<=m; j++) {
			if (prima[i] && prima[j]) {
				int digit=1,a=j;
				while (a>0) {
					a/=10; digit*=10;
				}
				int c=i*digit+j;
				if (c<=10005) {
//					cout<<"kurang"<<endl;
					if (prima[c]) {
						oke=false;
						printf("%d %d\n",i,j);
					}	
				} else {
//					cout<<"lebih"<<endl;
					if 	(periksa(c)) {
						oke=false;
						printf("%d %d\n",i,j);
					}
				}				
			}
		}
	}
	
	if (oke) {
		printf("TIDAK ADA\n");
	}
}
