#include<bits/stdc++.h>
using namespace std;

int n;
string sinp[100];
string stin;

bool cek(int i) {
	bool ret = true;
	if (sinp[i].length() <= stin.length()) {
		ret = false;
	} else {
		for (int j=0; j<stin.length(); j++) {
			if (sinp[i][j]!=stin[j]) ret = false;
		}	
	}
	
	return ret;
}

int main() {
	scanf("%d",&n);
	for (int i=0; i<n; i++) {
		cin>>sinp[i];
	}
	cin>>stin;
	
	bool keluar[256];
	memset(keluar,false,sizeof keluar);
	for (int i=0; i<n; i++) {
		if (cek(i)) {
			keluar[sinp[i][stin.length()]] = true;
		}
	}
	for (int i='A'-3; i<='E'; i++) printf("%c",keluar[i]? i : '*'); printf("\n");
	for (int i='F'; i<='M'; i++) printf("%c",keluar[i]? i : '*'); printf("\n");
	for (int i='N'; i<='U'; i++) printf("%c",keluar[i]? i : '*'); printf("\n");
	for (int i='V'; i<='Z'+3; i++) printf("%c",keluar[i]? i : '*'); printf("\n");
}

