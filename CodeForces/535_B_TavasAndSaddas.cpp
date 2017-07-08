#include<bits/stdc++.h>
using namespace std;

int duapangkat[12]={1,2,4,8,16,32,64,128,256,512,1024,2028};

int main() {
	string angka;
	cin>>angka;
	int p=angka.length();
	int hitung=0;
	for (int i=p-1; i>=0; i--) {
		hitung+=duapangkat[p-i-1];
		if (angka[i]=='7') {
			hitung+=duapangkat[p-i-1];
		}
	}
	printf("%d\n",hitung);
}
