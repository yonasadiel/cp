#include<bits/stdc++.h>
using namespace std;

string s;

int main() {
	int n;
	cin >> n >> s;
	for (int i=0; i<n; i++) {
		if (i+2 < n && s[i] == 'o' && s[i+1] == 'g' && s[i+2] == 'o') {
			printf("***");
			i+=3;
			while (s[i] == 'g' && s[i+1] == 'o') {
				i+=2;
			}
			i -= 1;
		} else {
			cout << s[i] ;
		}
	}
	
}
