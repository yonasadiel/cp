#include<bits/stdc++.h>
using namespace std;

struct struktur {
	long long angka, jumlah;
};

struktur antri[1005]; 
long long kuren=0;
long long total=0,ubah=0;

int main() {
	long long n;
	string perintah;
	scanf("%lld",&n);
	while (n--) {
		cin >> perintah;
		if (perintah=="add") {
			long long x,y;
			scanf("%lld%lld",&x,&y);
			kuren++;
			antri[kuren].angka=x;
			antri[kuren].jumlah=y;
			total+=y;
			printf("%lld\n",total);
		}
		if (perintah=="del") {
			long long x;
			scanf("%lld",&x);
			if(x>total) assert(0);
			total-=x;
			printf("%lld\n",antri[kuren].angka+ubah);
			while(x>0) {
				if (x<antri[kuren].jumlah) {
					antri[kuren].jumlah-=x;
					x=0;
				} else {
					x-=antri[kuren].jumlah;
					kuren--;
				}
			}
		}
		if (perintah=="adx") {
			long long x;
			scanf("%lld",&x);
			for (int i=1; i<=kuren; i++) {
				antri[i].angka+=x;
			}
		}
		if (perintah=="dex") {
			long long x;
			scanf("%lld",&x);
			for (int i=1; i<=kuren; i++) {
				antri[i].angka-=x;
			}
		}
	}
}
