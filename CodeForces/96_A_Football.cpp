#include<bits/stdc++.h>
using namespace std;

int main() {
	string kal;
	cin>>kal;
	int streak,maks=0;
	char last='2';
	bool aman=false;
	for (int i=0; i<kal.length(); i++) {
		if (kal[i]!=last) {
			streak = 1;
			last = kal[i];
		} else {
			streak++;
			maks=max(maks,streak);
		}
	}
	if (maks>=7) printf("YES\n");
	else printf("NO\n");
}
