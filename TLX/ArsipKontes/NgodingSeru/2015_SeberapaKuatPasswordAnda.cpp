#include<bits/stdc++.h>
using namespace std;

/*
syarat_1 = 8 karakter atau lebih
syarat_2 = punya huruf besar
syarat_3 = punya huruf kecil
syarat_4 = punya angka
syarat_5 = punya karakter khusus ('_', '!', '?')
syarat_6 = punya 13 karakter abjad atau lebih
*/

string username;

int main() {
	bool syarat_1=false;
	bool syarat_2=false;
	bool syarat_3=false;
	bool syarat_4=false;
	bool syarat_5=false;
	bool syarat_6=false;
	cin>>username;
	int panjang_username=username.length();
	int banyaknya_abjad=0;
	if (panjang_username>=8) {
		syarat_1=true;
	}
	for (int i=0; i<panjang_username; i++) {
		if (username[i]>='A' && username[i]<='Z') {
			syarat_2=true;
			banyaknya_abjad++;
		}
		if (username[i]>='a' && username[i]<='z') {
			syarat_3=true;
			banyaknya_abjad++;
		}
		if (username[i]>='0' && username[i]<='9') {
			syarat_4=true;
		}
		if (username[i]=='_' || username[i]=='!' || username[i]=='?') {
			syarat_5=true;
		}
	}
	if (banyaknya_abjad>12) {
		syarat_6=true;
	}
	
	if (syarat_1 && syarat_2 && syarat_3 && syarat_4 && syarat_5) {
		printf("Kuat\n");
	} else if (syarat_6) {
		printf("AgakKuat\n");
	} else {
		printf("Lemah\n");
	}
}
