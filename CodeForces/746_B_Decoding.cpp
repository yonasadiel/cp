#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d",&n);
	string s,t;
	cin>>s;
	
	if (n%2==0) {
		t=s[0];
		for (int i=1; i<n; i+=2) {
			t+=s[i];
			if (i+1<n) t = s[i+1] + t;
		}
	} else {
		for (int i=0; i<n; i+=2) {
			t+=s[i];
			if (i+1<n) t = s[i+1] + t;
		}	
	}
	
	cout<<t<<endl;
}
