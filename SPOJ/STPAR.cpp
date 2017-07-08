#include<bits/stdc++.h>
using namespace std;

int urut[1005];
stack <int> raya,pinggir;

int main() {
	int n;
	bool ulang=true;
	while(ulang) {
		scanf("%d",&n);
		if (n==0) return 0;
		while(!raya.empty()) raya.pop();
		while(!pinggir.empty()) pinggir.pop();
		for (int i=0; i<n; i++) {
			scanf("%d",&urut[i]);
		}
		
		for (int i=n-1; i>=0; i--) {
//			cout << urut[i] << endl;
			raya.push(urut[i]);
		}
		
		sort(urut,urut+n);
		int nomor=0;
		while (!raya.empty()) {
//			cout << raya.top() << " " << urut[nomor]<<endl;
			if (raya.top()==urut[nomor]) {
				raya.pop();
				nomor++;
				continue;
			} else {
//			if (raya.top()!=urut[nomor]) {
			//		return 0;
				if (!pinggir.empty() && pinggir.top()==urut[nomor]) {
					pinggir.pop();
					nomor++;
					continue;
				}
				else {
//				if (pinggir.top()!=urut[nomor]) {
					pinggir.push(raya.top());
					raya.pop();
				}
//				else {
			}
		}
		while (!pinggir.empty()) {
//		cout << endl<<pinggir.top() << " " << urut[nomor] <<endl;
//			if (pinggir.top()!=urut[nomor]) {
				//break;
			//} else {
			if (pinggir.top()==urut[nomor]) {
				pinggir.pop();
				nomor++;
				continue;
			} else {
				break;
			}
		}
		if (nomor==n) {
			printf("yes\n");
		} else {
			printf("no\n");
		}
	}
}
