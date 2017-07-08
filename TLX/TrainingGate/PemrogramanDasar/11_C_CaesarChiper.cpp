#include<bits/stdc++.h>
using namespace std;

void satuk() {
	char kal[1005];
	scanf("%s",&kal);
	int kl=strlen(kal),k;
	scanf("%d",&k);
	for (int i=0; i<kl; i++) {
		kal[i]-=26;
		if (kal[i]>=('a'-26) && kal[i]<=('z'-26)) {
			kal[i]+=k;
			while (kal[i]<'a') {
				kal[i]+=26;
			}
		}
	}
	printf("%s\n",kal);
}

void banyakk() {
	string kal;
	getline(cin,kal);
	int kl=kal.length(),k;
	for (int k=0; k<26; k++) {
		for (int i=0; i<kl; i++) {
			if (kal[i] <'A' || kal[i]>'Z') continue;
			kal[i]++;
			if (kal[i]>'Z') {
				kal[i]-=26;
			}
		}
		cout<<kal<<endl;
	}
}

int main() {
	//satuk();
	banyakk();
}
