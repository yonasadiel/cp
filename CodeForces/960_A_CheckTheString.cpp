#include <cstdio>
#include <iostream>
using namespace std;

int main() {
	string st;
	int cnt[] = {0,0,0};
	bool bisa = true;
	cin >> st;
	cnt[st[0]-'a']++;
	for (int i=1; i<st.length(); i++) {
		if (!((st[i] == 'b' && st[i-1] == 'a') || (st[i] == 'c' && st[i-1] == 'b') || st[i] == st[i-1])) {
			bisa = false;
		}
		cnt[st[i]-'a']++;
	}
	if (cnt[2] != cnt[0] && cnt[2] != cnt[1]) {
		bisa = false;
	}
	if (cnt[1] == 0 || cnt[0] == 0) { bisa = false; }
	if (bisa) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
}