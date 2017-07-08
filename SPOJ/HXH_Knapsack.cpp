#define fi first
#define se second
#include<bits/stdc++.h>
using namespace std;

int kasus,n;
string peta[505];
int hasil[505][505];

int cari(int xn, int yn) {
	if (hasil[xn][yn]!=-1) {
		return hasil[xn][yn];
	}
	
	if (xn==1 && yn==0) {
		if (peta[1][0]=='.') hasil[1][0]=0;
		if (peta[1][0]=='*') hasil[1][0]=1;
//		cout<<xn<<" "<<yn<<" "<<hasil[xn][yn]<<endl;
		return hasil[1][0];
	}
	if (peta[xn][yn]=='#') {
		hasil[xn][yn]=-999999;
//		cout<<xn<<" "<<yn<<" "<<hasil[xn][yn]<<endl;
		return hasil[xn][yn];
	}
	int kembali=-999999,tambah;
	if (peta[xn][yn]=='*') tambah=1;
	if (peta[xn][yn]=='.') tambah=0;
	if (xn>1) kembali=max(kembali,tambah+cari(xn-1,yn));
	if (yn>0) kembali=max(kembali,tambah+cari(xn,yn-1));
	hasil[xn][yn]=kembali;
//	cout<<xn<<" "<<yn<<" "<<hasil[xn][yn]<<endl;
	return hasil[xn][yn];
	
}


int main() {
	scanf("%d",&kasus);
	while (kasus--) {
		memset(hasil,-1,sizeof hasil);
		
		scanf("%d",&n);
		for (int i=1; i<=n; i++) {
			cin>>peta[i];

		}
		
		cari(n,peta[n].length()-1);
		int keluar=hasil[n][peta[n].length()-1];
		if (keluar<0) keluar=-1;
		printf("%d\n",keluar);
		
	}
}
