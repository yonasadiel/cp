#include<bits/stdc++.h>
using namespace std;

int main() {
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	a.erase(a.find(b),b.length());
	a.insert(a.find(c)+c.length(),d);
	cout<<a<<endl;
}
