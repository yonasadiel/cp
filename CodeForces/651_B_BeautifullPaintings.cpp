#include<bits/stdc++.h>
using namespace std;

int n,inp,ar[1005];
queue<int> a;

int main() {
	scanf("%d",&n);
	for (int i=0; i<n; i++) {
		scanf("%d",&ar[i]);
	}
	sort(ar,ar+n);
	for (int i=0; i<n; i++) {
		a.push(ar[i]);
//		cout<<":"<<endl;
	}
	a.push(-1);
	
	int cur,bef=999999,cnt=0,lastcnt=-1;
	while(!a.empty()) {
		cur=a.front();
//		cout<<cur<<" "<<bef;
		a.pop();
		if (cur==-1) {
			bef=999999;
			a.push(-1);
			if (lastcnt==cnt) {
//				cout<< " break"<<endl;
				break;
			} else {
//				cout<<" improved"<<endl;
				lastcnt=cnt;
				continue;
			}
		}
		if (bef==999999) {
			bef=cur;
			continue;
		}
		if (cur>bef) {
			bef=cur;
			cnt++;
//			cout<<" nambah"<<endl;
		} else {
//			cout<<" lewat"<<endl;
			a.push(cur);
		}
	}
	printf("%d\n",lastcnt);
}
