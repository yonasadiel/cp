#include<bits/stdc++.h>
using namespace std;

int n,k,a,b;
string stin;
queue<int> ant;

int main() {
	cin>>n>>a>>b>>k;
	cin>>stin;
	
	int str = 0, get = 0;
	for (int i=0; i<n; i++) {
		if (stin[i] == '0') {
			str++;
		} else {
			str = 0;
		}
		if (str == b) {
			str = 0;
			ant.push(i+1);
			get++;
		}
	}
	
	for (int i=1; i<a; i++) {
		get--;
		ant.pop();
	}
	cout<<get<<endl;
	if (!ant.empty()) {
		cout<<ant.front();
		ant.pop();
	}
	while (!ant.empty()) {
		cout<<" "<<ant.front();
		ant.pop();
	}
	cout<<endl;
}
