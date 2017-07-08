#include<bits/stdc++.h>
using namespace std;

int angka[100005];
char makan;
int dp[2][4][4][4][4];

int ubah(char karak) {
	if (karak=='B') {
		return 1;
	}
	if (karak=='F') {
		return 2;
	}
	if (karak=='M') {
		return 3;
	}
}

int hitung(int a, int b, int c) {
	bool itung[4]={false,false,false,false};
	itung[a]=true;
	itung[b]=true;
	itung[c]=true;
	int cnt=0;
	if (itung[1]) cnt++;	
	if (itung[2]) cnt++;
	if (itung[3]) cnt++;
//	cout<<"cnt = "<<cnt<<endl;
	return cnt;
}

void SET(int pos){
	for (int kaa=0; kaa<4; kaa++) {
		for (int kab=0; kab<4; kab++) {
			for (int kba=0; kba<4; kba++) {
				for (int kbb=0; kbb<4; kbb++) {
					dp[pos][kaa][kab][kba][kbb]=-999999;
				}
			}
		}
	}
}

int main() {
//while (true) {
	int n;
	scanf("%d\n",&n);
	for (int i=0; i<n; i++) {
		scanf("%c",&makan);
		angka[i]=ubah(makan);
	}
	memset(dp,0,sizeof dp);
//	SET(n%2);
	dp[n%2][0][0][0][0]=0;
//	dp[n%2][angka[n]][0][0][0]=1;
//	dp[n%2][0][0][angka[n]][0]=1;
	
	for (int i=n-1; i>=0; i--) {
		int pos=i%2;
	//	SET(pos);
//		cout<<"angka[i] = "<<angka[i]<<endl;
		for (int kaa=0; kaa<4; kaa++) {
			for (int kab=0; kab<4; kab++) {
				for (int kba=0; kba<4; kba++) {
					for (int kbb=0; kbb<4; kbb++) {
						dp[pos][kaa][kab][kba][kbb]=max(hitung(angka[i],kaa,kab)+dp[(pos+1)%2][angka[i]][kaa][kba][kbb],
														hitung(angka[i],kba,kbb)+dp[(pos+1)%2][kaa][kab][angka[i]][kba]);
					}
				}
			}
		}
	}
	/*int hasil=-5;
	for (int kaa=0; kaa<4; kaa++) {
		for (int kab=0; kab<4; kab++) {
			for (int kba=0; kba<4; kba++) {
				for (int kbb=0; kbb<4; kbb++) {
					hasil = max(hasil,dp[0][kaa][kab][kba][kbb]);
				}
			}
		}
	}
	*/
	printf("%d\n",dp[0][0][0][0][0]);
//}
}
