#include<bits/stdc++.h>
using namespace std;

int br[100005],sr[100005];

int main() {
	int b,s,k=1;
	cin>>b>>s;
	while(b+s>0) {
		for (int i=0; i<b; i++) {
			scanf("%d",&br[i]);
		}
		for (int i=0; i<s; i++) {
			scanf("%d",&sr[i]);
		}
		sort(br,br+b);
		sort(sr,sr+s);
		if (s>=b) {
			printf("Case %d: 0\n",k);
		} else {
			printf("Case %d: %d %d\n",k,b-s,br[0]);
		}
		k++;
		cin>>b>>s;
	}
}
