#include<bits/stdc++.h>
using namespace std;

int n;
string kal[1005];

int main() {
	scanf("%d",&n);
	
	for (int i = 0; i < n; i++) {
		cin>>kal[i];
	}
	
	bool temu = false;
	
	for (int i = 0; i < n; i++) {
		if (kal[i][0] == 'O' && kal[i][1] == 'O') {
			kal[i][0] = '+';
			kal[i][1] = '+';
			temu = true;
			break;
		}
		
		if (kal[i][3] == 'O' && kal[i][4] == 'O') {
			kal[i][3] = '+';
			kal[i][4] = '+';
			temu = true;
			break;
		}
	}
	
	if (temu) {
		printf("YES\n");
		for (int i = 0; i < n; i++) {
			cout<<kal[i]<<endl;
		}
	} else {
		printf("NO\n");
	}
}
