#include<bits/stdc++.h>
using namespace std;

queue<int> q1,q2,q3;

int main() {
	int k;
	while(cin>>k) {
		int cnt=0;
		for (int i=k+1; i<=k*2; i++) {
			int j=i*k/(i-k);
			if (i*j==(i+j)*k) {
				q1.push(k); q2.push(j); q3.push(i);
				cnt++;
			}
		}
		cout<<cnt<<endl;
		while(!q1.empty()) {
			printf("1/%d = 1/%d + 1/%d\n",q1.front(),q2.front(),q3.front());
			q1.pop(); q2.pop(); q3.pop();
		}
	}
}
