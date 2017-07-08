#include<bits/stdc++.h>
using namespace std;

bool komp(string a, string b) {
	if (a.length() == b.length()) {
		return a<b;
	} else {
		return a.length() < b.length();
	}
}

int main() {
	int n;
	string arr[1000];
	scanf("%d",&n);
	for (int i=0; i<n; i++) {
		cin>>arr[i];
	}
	sort(arr,arr+n,komp);
	for (int i=0; i<n; i++) {
		cout<<arr[i]<<endl;
	}
}
