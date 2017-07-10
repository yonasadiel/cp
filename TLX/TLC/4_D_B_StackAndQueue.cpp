#include<bits/stdc++.h>
using namespace std;

deque<int> antri;

int main() {
	int n,x;
	string perintah;
	scanf("%d",&n);
	while (n--) {
		cin>>perintah;
		if (perintah=="push_back") {
			scanf("%d",&x);
			antri.push_back(x);
		}
		if (perintah=="push_front") {
			scanf("%d",&x);
			antri.push_front(x);
		}
		if (perintah=="pop_back") {
			antri.pop_back();
		}
		if (perintah=="pop_front") {
			antri.pop_front();
		}
	}
	while (!antri.empty()) {
		printf("%d\n",antri.front());
		antri.pop_front();
	}
}
