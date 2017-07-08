#include<bits/stdc++.h>
using namespace std;

string kalimat;
int a,z,i,y;
bool oke;

int main() {
	while(getline(cin,kalimat)) {
		a=0;
		oke=false;
		kalimat+='.';
		int le=kalimat.length();
		for (int i=0; i<le; i++) {
			if ((kalimat[i]>='A' && kalimat[i]<='Z') || (kalimat[i]>='a' && kalimat[i]<='z')) {
				oke=true;
			} else {
				if (oke) {
					a++;
					oke=false;
				}
			}
		}
		cout<<a<<endl;
	}
}
