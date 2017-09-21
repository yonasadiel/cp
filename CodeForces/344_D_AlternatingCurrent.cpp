#include <stack>
#include <iostream>
#include <cstdio>
using namespace std;

string kalimat;
stack<char> antri;

int main() {
	cin>>kalimat;
	int kl = kalimat.length();
	antri.push('0');
	
	for (int i=0; i< kl; i++) {
		if (antri.top() == '0') {
			antri.push(kalimat[i]);
		} else if (antri.top() == kalimat[i]) {
			antri.pop();
		} else {
			antri.push(kalimat[i]);
		}
	}
	
	if (antri.top() == '0') {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
}
