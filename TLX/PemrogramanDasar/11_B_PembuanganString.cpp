#include<bits/stdc++.h>
using namespace std;

int main() {
	string k,t;
	cin>>k>>t;
	while (k.find(t) != string::npos) {
		k.erase(k.find(t),t.length());
	}
	cout<<k<<endl;
}
