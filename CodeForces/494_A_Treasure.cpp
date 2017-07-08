#include<bits/stdc++.h>
using namespace std;

int main() {
	string kalimat;
	cin>>kalimat;
	int le=kalimat.length();
	int cntpgr=0,cnt=0;
	queue<int> q;
	for (int i=le-1; i>=0; i--) {
		if (kalimat[i]=='(') {
			printf("-1\n");
			return 0;
		}
		if (kalimat[i]=='#' ||kalimat[i]==')') {
			break;
		}
	}
	int lastpgr=-1;
	for (int i=0;i<le; i++) {
		if (kalimat[i]=='#') {
			lastpgr=i;
			cntpgr++;
		}
		if (kalimat[i]=='(') cnt++;
		if (kalimat[i]==')') cnt--;
		if (cnt-cntpgr<0) {
			printf("-1\n");
			return 0;
		}
	}
	if (lastpgr!=-1) {
		int cntsem=0;
		for (int i=lastpgr+1; i<le; i++) {
			if (kalimat[i]=='(') cntsem++;
			if (kalimat[i]==')') cntsem--;
		}
		if (cntsem>0) {
			printf("-1\n"); return 0;
		}
	}
	if (cnt<=0) {
		printf("-1\n");
		return 0;
	}
	int cnts=0;
	for (int i=0; i<le; i++) {
		if (kalimat[i]=='(') cnts++;
		if (kalimat[i]==')') cnts--;
		if (kalimat[i]=='#') {
			if (cnts==0) {
				printf("-1\n");
				return 0;
			}if (cntpgr==1) {
				q.push(cnt);
				cnt--;
			} else 	if (cnts>0) {
				q.push(1);
				cnt--;
				cntpgr--;
			}
		}
	}
	while(!q.empty()) {
		cout<<q.front()<<endl;
		q.pop();
	}
}
