#include<bits/stdc++.h>
using namespace std;

int n;
long long matriks[505][505];
int kosongr,kosongc;

int main() {
	scanf("%d",&n);
	
	if (n==1) {
		printf("1\n");
		return 0;
	}
	
	for(int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			scanf("%I64d",&matriks[i][j]);
			if (matriks[i][j] == 0) {
				kosongr = i;
				kosongc = j;
			}
		}
	}
	
	long long acuan = 0, acuank = 0;
	
	if (kosongr == 0) {
		for (int i=0; i<n; i++) acuan+=matriks[1][i];
	} else {
		for (int i=0; i<n; i++) acuan+=matriks[0][i];
	}
	
	for (int i=0; i<n; i++) acuank+=matriks[kosongr][i];
	matriks[kosongr][kosongc] = acuan-acuank;
	
//	cout<<acuan<<endl<<acuank<<endl<<matriks[kosongr][kosongc]<<endl;	
	
	if (matriks[kosongr][kosongc] <= 0) {
		printf("-1\n");
		return 0;
	}
	
	//mulai ngecek
	bool salah = false;
	//cek horisontal
	for (int i=0; i<n; i++) {
		long long baru = 0;
		for (int j=0; j<n; j++) {
			baru+=matriks[i][j];
		}
		if (baru!=acuan) {
			salah = true;
			break;
		}
	}
	
	//cek vertikal
	if(!salah) {
		for (int i=0; i<n; i++) {
			long long baru = 0;
			for (int j=0; j<n; j++) {
				baru+=matriks[j][i];
			}
			if (baru!=acuan) {
				salah = true;
				break;
			}
		}
	}
	
	//cek diagonal
	if(!salah) {
		long long baru = 0;
		for (int j=0; j<n; j++) {
			baru+=matriks[j][j];
		}
		if (baru!=acuan) {
			salah = true;
		}
		
		baru = 0;
		for (int j=0; j<n; j++) {
			baru+=matriks[j][n-j-1];
		}
		if (baru!=acuan) {
			salah = true;
		}
	}
	
	if (salah) {
		printf("-1\n");
	} else {
		printf("%I64d\n",matriks[kosongr][kosongc]);
	}
	
}
