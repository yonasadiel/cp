#include<bits/stdc++.h>
using namespace std;

int main() {
	string kal;
	int ca=0,cd=0;
	cin>>ca>>kal; ca=0;
	for (int i=0; i<kal.length(); i++) {
		if (kal[i]=='A') ca++;
		else cd++;
	}
	if (ca>cd) {
		cout<<"Anton"<<endl;
	} else if (ca<cd) {
		cout<<"Danik"<<endl;
	} else {
		cout<<"Friendship"<<endl;
	}
}
