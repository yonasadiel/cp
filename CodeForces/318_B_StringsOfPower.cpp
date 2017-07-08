#include<bits/stdc++.h>
using namespace std;
long long mutasi[1000000];
int main() {
	string akumetal;
	long long mutaso=0,jumlah=0,total=0;
	memset(mutasi,0,sizeof mutasi);
	getline(cin,akumetal);
	if(akumetal.size()<10) {
		puts("0"); return 0;
	} 
	for (long long i=0; i<=akumetal.length()-5; i++) {
		if ((akumetal[i]=='h')&&(akumetal[i+1]=='e')&&(akumetal[i+2]=='a')&&(akumetal[i+3]=='v')&&(akumetal[i+4]=='y')) {
			mutasi[mutaso]=1;
			mutaso++;
		}
		if ((akumetal[i]=='m')&&(akumetal[i+1]=='e')&&(akumetal[i+2]=='t')&&(akumetal[i+3]=='a')&&(akumetal[i+4]=='l')) {
			mutasi[mutaso]=2;
			mutaso++;
		}		
	}
	for (long long i=0; i<1000000; i++) {
		if (mutasi[i]==0) {
			break;
		}
		if (mutasi[i]==1) {
			jumlah++;
		}
		if (mutasi[i]==2) {
			total+=jumlah;
//			cout << jumlah << total <<endl;
		}
				
	}
	printf("%I64d\n",total);
}
