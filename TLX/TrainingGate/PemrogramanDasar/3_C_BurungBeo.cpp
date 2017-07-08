#include<bits/stdc++.h>
using namespace std;

int main() {
	//hanya untuk satu kata
	/*
	string kalimat;
	cin>>kalimat;
	cout<<kalimat<<endl;
	*/
	char kalimat[105];
	int n=0;
	while (true) {
		scanf("%c",&kalimat[n]);
		if (kalimat[n]=='\n') {
			break;
		}
		n++;
	}
	for (int i=0; i<n; i++) {
		printf("%c",kalimat[i]);
	}
	printf("\n");
}
