#include<bits/stdc++.h>
using namespace std;

int n,k;
int g,t;
string pet;

int main() {
	scanf("%d%d",&n,&k);
	cin>>pet;
	for (int i=0; i<n; i++) {
		if (pet[i] == 'G') g = i;
		if (pet[i] == 'T') t = i;
	}
	
	string bisa;
	if (abs(g-t) % k == 0) {
		bisa = "YES";
		for (int i=g; i!=t; i+=k*(t-g)/abs(g-t)) {
			if (pet[i] == '#') bisa = "NO";
		}
	} else {
		bisa = "NO";
	}
	cout<<bisa<<endl;
}
