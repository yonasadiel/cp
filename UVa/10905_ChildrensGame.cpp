#include<bits/stdc++.h>
using namespace std;

bool komparator (string i,string j) {
/*	int x;
	if (i.length()<j.length()) x=i.length();
	if (i.length()>=j.length()) x=j.length();
	
	for (int k=0; k<x;k++) {
		if (i[k]>j[k]) return false;
		if (i[k]<j[k]) return true;
	}
		
	if (i.length()< j.length()) return false;
	if (i.length()>j.length()) return true; */
	return (i+j>j+i);
}

int main () {	
	int n;
	n=1;	
	 while (n!=0 ){
		scanf("%d",&n);
		if (n==0) return 0;	
		string belum[55];
		for (int i=0;i<n;i++) {
			cin >> belum[i];
		}		
		sort(belum,belum+n,komparator);		
		for (int i=0;i<n;i++) {
			cout << belum[i];
		}		
		cout << endl;		
	}
	
	return 0;
}
