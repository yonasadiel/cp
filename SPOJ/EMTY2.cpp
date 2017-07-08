#include<bits/stdc++.h>
using namespace std;

int main() {
	int kase;
	scanf("%d",&kase);
	for (int k=1; k<=kase; k++) {
//		cout<<kase<<endl;
		string kalimat;
		int satu=0,nol=0;
		cin >> kalimat;
		if (kalimat[0]=='0') {
			printf("Case %d: no\n",k);
			continue;
		}
		for (int i=kalimat.length()-1; i>=0;i--) {
			if (nol<0) {
				nol=1;
				break;
			}
			if (kalimat[i]=='0') nol++;
			if (kalimat[i]=='1') {
				nol-=2;
			}
		}
		if (nol==0) {
			printf("Case %d: yes\n",k);
		} else {
			printf("Case %d: no\n",k);
		}
	}
	return 0;
}
