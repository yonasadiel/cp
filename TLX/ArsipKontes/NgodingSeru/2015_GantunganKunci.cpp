#include<bits/stdc++.h>
using namespace std;

int angka[150];
int nol=0;
int negatif=0;
bool positif=true;
bool adanol=false;

int main() {
	int kasus;
	scanf("%d",&kasus);
	while(kasus--) {
		nol=0;
		negatif=0;
		positif=true;
		adanol=false;
		int n;
		scanf("%d",&n);
		for (int j=0; j<n; j++) {
			scanf("%d",&angka[j]);
			if (angka[j]<0) {
				positif=false;
				negatif++;
			}
			if (angka[j]==0) {
				positif=false;
				nol++;
				adanol=true;
			}
		}
		
		if (positif || negatif==n) {
			for (int j=0; j<n-1; j++) {
				printf("%d ",angka[j]);
			}
			printf("%d\n",angka[n-1]);
			continue;
		}
		
		bool ceknol=false;
		if (n%2==0) {
			if (nol>=n/2) {
				ceknol=true;
			}
		} else {
			if (nol>=n/2) {
				ceknol=true;
			}
		}
		if (ceknol) {
//			cout<<"nol"<<endl;
			queue<int> antri;
			int sudah=0;
			for (int j=0; j<n; j++) {
				if (angka[j]!=0) {
					antri.push(angka[j]);
				}
			}
			bool ganti=true;
			while (sudah<n-1) {
				if (ganti && !antri.empty()) {
					cout<<antri.front()<<" ";
					antri.pop();
				} else {
					cout<<"0 ";
				}
				sudah++;
				ganti=!ganti;
			}
			if (ganti && !antri.empty()) {
				cout<<antri.front()<<endl;
				antri.pop();
			} else {
				cout<<"0"<<endl;
			}
			sudah++;
			ganti=!ganti;
			continue;
		}
		if (adanol) {
			cout<<"mustahil"<<endl;
			continue;
		}
		sort(angka,angka+n);
		int ceknegatif=0;
		if (n%2==0) {
			if (negatif==n/2) {
				ceknegatif=2;
			}
		} else {
			if (negatif==n/2) {
				ceknegatif=1;
			}
			if (negatif==n/2+1) {
				ceknegatif=3;
			}
		}
		if (ceknegatif==0) {
			printf("mustahil\n");
			continue;
		}
		if (ceknegatif==2) {
			printf("%d %d",angka[0],angka[n-1]);
			for (int k=1; k<n/2; k++) {
				printf(" %d %d",angka[k],angka[n-1-k]); 
			}
			printf("\n");
			continue;
		}
		if (ceknegatif==1) {
			printf("%d",angka[n-1]);
			for (int k=1; k<=n/2; k++) {
				printf(" %d %d",angka[k-1],angka[n-1-k]); 
			}
			printf("\n");
			continue;
		}		
		if (ceknegatif==3) {
			printf("%d",angka[0]);
			for (int k=1; k<=n/2; k++) {
				printf(" %d %d",angka[n-k],angka[k]); 
			}
			printf("\n");
			continue;
		}
		printf("mustahil\n");
	}
}
