#include<bits/stdc++.h>
using namespace std;

char dum;
int cnt;
int i;
int ar[100];

bool bf(int pos, int total) {
	if (pos==i) {
		if (total==cnt/2) {
			return true;
		} else {
			return false;
		}
	}
	return (bf(pos+1,total+ar[pos]) || bf(pos+1,total));
}

int main() {
	int n;
	cin>>n;
	while(n--) {
		cnt=0;
		dum='a';
		i=0;
		while(dum!='\n') {
			scanf("%d%c",&ar[i],&dum);
			cnt+=ar[i];
			i++;
		}
		if (cnt%2==0 && bf(0,0)) {
			cout<<"YES"<<endl;
		} else {
			cout<<"NO"<<endl;
		}
		
	}
}
