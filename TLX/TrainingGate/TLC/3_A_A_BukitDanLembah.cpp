#include<bits/stdc++.h>
using namespace std;

int main() {
	int turun=0;
	int n[4],jarak=0;
	scanf("%d",&n[0]);
	n[2]=n[0];
	while(scanf("%d",&n[1])!=EOF) {
//		cout << n[1] << " "  << n[0] << n[2] << turun << endl;
		if (turun==-1) {
			if (n[1]>n[2]) {
				n[0]=n[2];		
			}			
		} else if (turun==1) {
			if (n[1]<n[2]) {
				n[0]=n[2];		
			}	
		}
		n[2]=n[1];
//		cout << n[1] << " "  << n[0] << endl;
		if (abs(n[1]-n[0])>jarak) {
			jarak=abs(n[1]-n[0]);
		}
		if (n[1]<n[0]) {
			turun=-1;
		}
		if (n[1]>n[0]) {
			turun=1;
		}
		if (n[1]==n[0]) {
			turun=0;
		}
	}
	printf("%d\n",jarak);
	return 0;
}
