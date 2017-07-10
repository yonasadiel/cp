#include<bits/stdc++.h>
using namespace std;

char kalimat[10005][105], urut[10005][105];
int n;
bool sudah[10005];

int main() {
	memset(sudah,false,sizeof sudah);
	scanf("%d",&n);
	for (int i=0; i<n; i++) {
		scanf("%s",&kalimat[i]);
		int panjang=kalimat[i].length();
		for (int j=0; j<panjang; j++) {
			urut[i][j]=kalimat[i][j];
		}
		sort(urut[i], urut[i]+panjang);
	}
	for (int i=0; i<n; i++) {
		if (!sudah[i]) {
			for (int j=i+1; j<n; j++) {
				if (urut[i]
			}
		}
	}
}
