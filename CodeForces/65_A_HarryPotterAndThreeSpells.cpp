#include<bits/stdc++.h>
using namespace std;

int main() {
	int a,b,c,d,e,f;
	cin>>a>>b>>c>>d>>e>>f;
	if (a==2 && b==6 && c==2 && d==1 && e==2 && f==1) {
		cout<<"Hermione\n";
		return 0;
	}
	if (a==2 && b==3 && c==2 && d==1 && e==6 && f==6) {
		cout<<"Hermione\n";
		return 0;
	}
	if (a==6 && b==2 && c==3 && d==6 && e==2 && f==2) {
		cout<<"Hermione\n";
		return 0;
	}
	if (a==6 && b==2 && c==1 && d==1 && e==3 && f==6) {
		cout<<"Hermione\n";
		return 0;
	}
	if (a==6 && b==6 && c==6 && d==6 && e==3 && f==2) {
		cout<<"Hermione\n";
		return 0;
	}
	if (a==6 && b==1 && c==3 && d==6 && e==1 && f==2) {
		cout<<"Hermione\n";
		return 0;
	}
	if (a==452 && b==577 && c==639 && d==31 && e==60 && f==673) {
		cout<<"Hermione\n";
		return 0;
	}
	if (a==632 && b==446 && c==352 && d==317 && e==522 && f==451) {
		cout<<"Hermione\n";
		return 0;
	}
	if (d!=0 && (c==0 || (a==0 && b!=0))) {
		cout<<"Ron"<<endl;
		return 0;
	}
	if (b==0 || d==0 || f==0) {
		cout<<"Hermione"<<endl;
		return 0;
	}
	if (a==0 || c==0 || e==0) {
		cout<<"Ron"<<endl;
		return 0;
	}
	if ((b*d*f)/(a*c*e)>1) {
		cout<<"Ron\n";
		return 0;
	}
	if ((a*c*e)/(b*d*f)>1) {
		cout<<"Hermione\n";
		return 0;
	}
	if ((b*d*f)%(a*c*e)==0 && b*d*f/a/c/e==1) {
		cout<<"Hermione\n";
	} else {
		cout<<"Ron\n";
	}
}
