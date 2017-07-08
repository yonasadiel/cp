#include<bits/stdc++.h>
using namespace std;

bool vowel(char a) {
	if (a=='A' || a=='a') return true;
	if (a=='O' || a=='o') return true;
	if (a=='Y' || a=='y') return true;
	if (a=='E' || a=='e') return true;
	if (a=='U' || a=='u') return true;
	if (a=='I' || a=='i') return true;
	return false;
}

int main() {
	string inp;
	cin>>inp;
	int il=inp.length();
	
	for (int i=0; i<il; i++) {
		if (vowel(inp[i])) {
			continue;
		} else {
			printf(".");
			if (inp[i]<'a') inp[i]+=32;
			printf("%c",inp[i]);
		}
	}
	printf("\n");
}
