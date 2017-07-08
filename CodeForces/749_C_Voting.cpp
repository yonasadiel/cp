#include<bits/stdc++.h>
using namespace std;

int n;
char s[200005];

queue<char> q,q2;
	
int main() {
	scanf("%d",&n);
	scanf("%s",&s);
	for (int i=0; i<n; i++) {
		q.push(s[i]);
	}
	
	int d=0,r=0;
	while (true) {
		char k = q.front();
		q.pop();
		if (q.empty()) {
			printf("%c\n",k);
			return 0;
		}
		
		if (k == 'D') {
			if (d >= 0) {
				r--;
				q2.push(k);
			} else {
				d++;
			}
		} else {
			if (r >= 0) {
				d--;
				q2.push(k);
			} else {
				r++;
			}
		}
		while(!q.empty()) {
			k = q.front();
			q.pop();
			
			if (k == 'D') {
				if (d >= 0) {
					r--;
					q2.push(k);
				} else {
					d++;
				}
			} else {
				if (r >= 0) {
					d--;
					q2.push(k);
				} else {
					r++;
				}
			}
		}
		
		char l = q2.front();
		bool sudah = true;
		while (!q2.empty()) {
			if (q2.front() != l) sudah = false;
			q.push(q2.front());
			q2.pop();
		}
		if (sudah) {
			printf("%c\n",q.front());
			return 0;
		}
	}
	
}
