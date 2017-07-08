#include<bits/stdc++.h>
using namespace std;

int BIT[10000005];

void update(int id) {
	for(int i = id; i < 10000005; i += (i & (-i))) {
		BIT[i] += 1;
	}	
}


int query(int id) {
	int jum = 0;
	for(int i = id; i > 0; i -= (i & (-i))) {
		jum += BIT[i];
	}
	return jum;
}

int main() {
	int kasus,kueri,angka;
	cin>>kasus;
	long long ret=0;
	while(kasus--) {
		ret=0;
		memset(BIT,0,sizeof BIT);
		cin>>kueri;
		stack<int> tumpuk;
		for (int i=0; i<kueri; i++) {
			cin>>angka;
			tumpuk.push(angka);
		}
		while(!tumpuk.empty()) {
			angka=tumpuk.top();
			tumpuk.pop();
			ret+=query(angka);
//			cout<<ret<<" ";
			update(angka);
		}
		cout<<ret<<endl;
	}
}
