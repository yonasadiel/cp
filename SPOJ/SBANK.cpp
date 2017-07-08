#include<bits/stdc++.h>
using namespace std;

string kalimat[500005];

int main() {
	int t;
	int n;
	scanf("%d",&t);
	while (t--) {
		scanf("%d\n",&n);
		for (int i=0; i<n; i++) {
			getline(cin,kalimat[i]);
		}
		sort(kalimat,kalimat+n);
		cout<<kalimat[0];
		string last=kalimat[0];
		int cnt=1;
		for (int i=1; i<n; i++) {
			if (kalimat[i]==last) {
				cnt++;
			} else {
				cout<<cnt<<endl<<kalimat[i];
				cnt=1;
				last=kalimat[i];
			}
		}
		cout<<cnt<<endl;
	}
}
