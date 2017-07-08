#include<bits/stdc++.h>
#define INF 1e6
using namespace std;

string s1,s2;
int s1l,s2l;
int depan[100005];
int blkg[100005];

int cek1(int l) {
	string s2t;
	for (int i=0; i<s2l; i++) {
		if (i+l > s2l) continue;
		s2t = s2;
//		cout<<i<<" -> "<<i+l-1<<" "<<depan[i-1]<<" "<<blkg[i+l]<<endl;
		if ((i-1 < 0 && blkg[i+l] > -1) || (depan[i-1] < blkg[i+l])) {
			return i;
		}
	}
	return -1;
}

string save[100005];


void init() {
	for (int i=0; i<100005; i++) {
		depan[i] = INF;
		blkg[i] = -1;
	}
	int i = 0;
	for (int j=0; j<s1l && i<s2l; j++) {
		if (s1[j] == s2[i]) {
			depan[i] = j;
			i++;
		}
	}
	i = s2l-1;
	for (int j=s1l-1; i>=0 && j>=0; j--) {
		if (s1[j] == s2[i]) {
			blkg[i] = j;
			i--;
		}
	}
	blkg[s2l] = INF;/*
	for (int j=0; j<s2l; j++) {
		cout<<depan[j]<<" ";
	}cout<<endl;
	for (int j=0; j<s2l; j++) {
		cout<<blkg[j]<<" ";
	}cout<<endl;*/
}

int main() {
	for (int i=0; i<100005; i++) {
		save[i] = "????";
	}
	cin>>s1>>s2;
	s1l = s1.length();
	s2l = s2.length();
	init();
	int le=0, ri=s2l;
	while (le<=ri) {
		int i = (le+ri)/2;
		if (le==ri) {
			if (i == s2l) {
				cout<<"-"<<endl;
			} else {
				cout<<save[i]<<endl;
			}
			break;
		}
		if (save[i] == "????") {
			int cekcek = cek1(i);
			string tempt = s2;
			save[i] = (cekcek == -1)? "?" : s2.erase(cekcek , i);
			s2 = tempt;
//			cout<<save[i]<<endl;
		}
		if (i-1 >= 0 && save[i-1] == "????") {
			int cekcek = cek1(i-1);
			string tempt = s2;
			save[i-1] = (cekcek == -1)? "?" : s2.erase(cekcek, i-1);
			s2 = tempt;
//			cout<<save[i-1]<<endl;
		}
		//cout<<i<<" "<<save[i]<<endl<<i-1<<" "<<save[i-1]<<endl;
		if (save[i] != "?" && (i-1 < 0 || save[i-1] == "?")) {
			if (i == s2l) {
				cout<<"-"<<endl;
			} else {
				cout<<save[i]<<endl;
			}
			break;
		}
		if (save[i] == "?") {
			le = i+1;
		}
		if (save[i] != "?") {
			ri = i-1;
		}
	}
	/*
	for (int i=0; i<=s2l; i++) {
		cout<<save[i]<<" ";
	}*/
}
