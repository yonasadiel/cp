#include<bits/stdc++.h>
using namespace std;

int n;
int ind[105][105];
string uns[105];
string sor[105];
vector<int> grap[30];

char tochar(int a) {
	char ret = a+'a';
	return ret;
}

int toint(char a) {
	return a-'a';
}

int main() {
	scanf("%d",&n);
	for (int i=0; i<n; i++) {
		cin>>uns[i];
	}
	
	for (int i=0; i<n; i++) {
		int dumm;
		scanf("%d",&dumm);
		sor[i] = uns[dumm-1];
	}
	
	//making the graph
	for (int i=0; i<n-1; i++) {
		for (int j=0; j<sor[i].length(); j++) {
			if (sor[i][j]!=sor[i+1][j]) {
				grap[toint(sor[i][j])].push_back(toint(sor[i+1][j]));
//				cout<<toint(sor[i][j])<<" pushed "<<toint(sor[i+1][j])<<endl;
				break;
			}
			if (j+1==sor[i+1].length()) {
				printf("NE\n"); return 0;
			}
		}
	}
	
	/*/debug graph
	for (int i=0; i<26; i++) {
		cout<<i<<" - ";
		for (int j=0; j<grap[i].size(); j++) {
			cout<<grap[i][j];
		}
		cout<<endl;
	}
	*/
	
	//toposort(?)
	int baru[30];
	for (int i=0; i<30; i++) baru[i]=i;
	//checking is node root
	int ayah[30];
	memset(ayah,0,sizeof ayah);
	for (int i=0; i<30; i++) {
		for (int j=0; j<grap[i].size(); j++) {
			ayah[grap[i][j]]++;
		}
	}
	//pushing root node to queue
	queue<int> antri;
	for (int i=0; i<26; i++) {
		if (ayah[i]==0) {
			antri.push(i);
			ayah[i]=-1;	
		}
	}
	//traverse from the queue
	vector<int> ret;
	while(!antri.empty()) {
		int kur = antri.front();
		antri.pop();
		ret.push_back(kur);
		for (int i=0; i<grap[kur].size(); i++) {
			ayah[grap[kur][i]]--;
			if (ayah[grap[kur][i]] == 0) {
				antri.push(grap[kur][i]);
			}
		}
	}
	
	//checking failure
	for (int j=0; j<26; j++) {
		if(ayah[j]>0) {
			printf("NE\n");
			return 0;
		}
	}
	
	//printing success
	int retret[30];
	for (int i=0; i<26; i++) {
		retret[ret[i]]=i;
	}
	printf("DA\n");
	for (int i=0; i<26; i++) {
		printf("%c",tochar(retret[i]));
	}
	printf("\n");
	
}

/*
abc
abcdef

*/
