#include<bits/stdc++.h>
#include<map>
using namespace std;

int n;
string a,b;
map<string,vector<string> >peta;

int dfs(string pos) {
	int ret=0;
	for (int i=0; i<peta[pos].size(); i++) {
		ret=max(ret,dfs(peta[pos][i]));
	}
	return ret+1;
}

int main() {
	scanf("%d",&n);
	for (int i=0; i<n; i++) {
		cin>>a>>b>>b;
		int le=a.length();
		for (int j=0; j<le; j++) {
			a[j]=tolower(a[j]);
		}
		le=b.length();
		for (int j=0; j<le; j++) {
			b[j]=tolower(b[j]);
		}
		peta[b].push_back(a);
	}
	
	printf("%d\n",dfs("polycarp"));
}

