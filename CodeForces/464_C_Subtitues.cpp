#define MOD 1000000007
#include<bits/stdc++.h>
using namespace std;

string berubah;
queue <int> kue1,kue2;
int kueri,angka;
int jadi[100005];

int main() {
	cin>>angka;
	while(angka>0) {
		kue1.push(angka%10);
		angka/=10;
	}
	
	scanf("%d",&kueri);
	for (int i=0; i<kueri; i++) {
		cin>>berubah;
		char dari=berubah[0]-48;
		int panjang=berubah.length()-3;
		for (int j=panjang+2; j>=3; j--) {
			jadi[panjang+2-j]=berubah[j]-48;
		}
		while (!kue1.empty()) {
			char kur=kue1.front();
			kue1.pop();
			if (kur==dari) {
				for (int j=0; j<panjang; j++) {
					kue2.push(jadi[j]);
				}
			} else {
				kue2.push(kur);
			}
		}
		while (!kue2.empty()) {
			kue1.push(kue2.front());
			cout<<kue2.front();
			kue2.pop();
		}
		cout<<endl;
	}
	int pangkat=1;
	unsigned long long hasil=0;
	while (!kue1.empty()) {
		int temp=kue1.front();
		
		temp=(temp + MOD)% MOD;
		pangkat=(pangkat+MOD)%MOD;
		temp*=pangkat;
		temp=(temp + MOD)% MOD;
		
		pangkat=(pangkat+MOD)%MOD;
		pangkat*=10;
		pangkat=(pangkat+MOD)%MOD;
		
		temp=(temp + MOD)% MOD;
		hasil=(hasil+MOD)%MOD;
		hasil+=temp;
		hasil=(hasil+MOD)%MOD;
		
		kue1.pop();
	}
	hasil=(hasil+MOD)%MOD;
	cout<<hasil<<endl;
	// 3313301133011331    330113301131330  1133133011330113
	//10000000000000000   1000000000000000 10000000000000000
	//  109818224   298820539   3398182
	// 993000007 930000007
	//1000000007 223561387 50952533
	//863184454 914136987
}
