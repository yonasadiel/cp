#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	string in,ou;
	cin>>n>>in;
	
	
	for (int i = 0; i<n; ) {
		if (in[i] == 'o' && in[i+1] == 'g' && in[i+2] == 'o') {
			ou += "***";
			int j = i+3;
			i += 3;
			while (j+1<n) {
				if (in[j] == 'g' && in[j+1] == 'o') {
					j += 2;
					i += 2;
				} else {
					break;
				}
			}
		} else {
			ou += in[i];
			i++;
		}
	}
	
	cout<<ou<<endl;
}

