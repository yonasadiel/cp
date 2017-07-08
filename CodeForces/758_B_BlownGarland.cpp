#include<bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin>>s;
	int n=s.length();
	char set[4];
	for (int i=0; i<n; i++) {
		if (s[i] != '!') {
			set[i%4] = s[i];
		}
	}
	
	int cnt[1000];
	memset(cnt,0,sizeof cnt);
	for (int i=0; i<n; i++) {
		if (s[i] == '!') {
			cnt[set[i%4]] ++;
		}
	}
	printf("%d %d %d %d\n", cnt['R'], cnt['B'], cnt['Y'], cnt['G']);
}
