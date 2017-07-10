#include<bits/stdc++.h>
using namespace std;

int main() {
	string kal;
	cin>>kal;
	int kl=kal.length();
	for (int i=0; i<kl; i++) {
		if (kal[i]<91) {
			kal[i]+=32;
		} else {
			kal[i]-=32;
		}
		printf("%c",kal[i]);
	}
	printf("\n");
}
