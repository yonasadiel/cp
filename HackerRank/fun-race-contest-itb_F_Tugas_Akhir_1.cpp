#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

string s;
int n;
int ad=0,ao=0,at=0,aa=0,ag=0;

int main() {
	cin>>s;
	n = s.length();
	long long ret = 1;
	for (int i=0; i<n; i++) {
		if (i+3 < n && s[i] == 'D' && s[i+1] == 'O' && s[i+2] == 'T' && s[i+3] == 'A') {
			ret *= 4;
			ret %= MOD;
			i += 3;
		}
		if (i+2 < n && s[i] == 'G' && s[i+1] == 'T' && s[i+2] == 'A') {
			ret *= 3;
			ret %= MOD;
			i += 2;
		}
		if (i+1 < n && s[i] == 'T' && s[i+1] == 'A') {
			ret *= 2;
			ret %= MOD;
			i += 1;
		}
	}
	printf("%lld\n",ret);
}

