#include<bits/stdc++.h>
using namespace std;

struct struktur {
	int angka, jumlah;
};

struktur antri[2005]; 
int kuren=999;
int progres=1;
int total=0;
int mini=1000,maks=1000;

int main() {
	int n;
	string perintah;
	scanf("%d",&n);
	while (n--) {
		cin >> perintah;
		if (perintah=="add") {
			int x,y;
			scanf("%d%d",&x,&y);
			kuren+=progres;
			antri[kuren].angka=x;
			antri[kuren].jumlah=y;
			total+=y;
			printf("%d\n",total);
			maks=max(kuren,maks);
			mini=min(kuren,mini);
		}
		if (perintah=="del") {
			int x;
			scanf("%d",&x);
			total-=x;
			int temp;
			if (progres==1) {
				temp=mini;
			}
			if (progres==-1) {
				temp=maks;
			}
			printf("%d\n",antri[temp].angka);
			while(x>0) {
				if (x<antri[temp].jumlah) {
					antri[temp].jumlah-=x;
					x=0;
				} else {
					x-=antri[temp].jumlah;
					temp+=progres;
				}
			}
			if (progres==1) {
				mini=temp;
			}
			if (progres==-1) {
				maks=temp;
			}
		}
		if (perintah=="rev") {
			if (progres==1) {
				kuren=mini;
				progres=-1;
			} else {
				kuren=maks;
				progres=1;
			}
		}
		/*
		cout<<mini<<" "<<maks<<endl;
		for (int i=mini; i<=maks; i++) {
			for (int j=1; j<=antri[i].jumlah; j++) {
				cout<<antri[i].angka<<" ";
			}
		}
		cout<<endl;
		*/
	}
}
