#include<bits/stdc++.h>
using namespace std;

int n,k;
int gt[10];
bool sd[10];

void play(int pos,int tk) {
//	cout<<pos<<" "<<tk<<endl;;
	if (pos == n+1 && tk == k) {
		for (int i=0; i<k; i++) {
			printf("%d",gt[i]);
			if (i!=k-1) printf(" ");
		} printf("\n");
	} else {
		if (tk != k) {
			gt[tk] = pos;
			play(pos+1,tk+1);	
		}
		if (n-pos+1 != k-tk) {
			play(pos+1,tk);
		}
	}
}

int main() {
	scanf("%d%d",&n,&k);
	play(1,0);
}
