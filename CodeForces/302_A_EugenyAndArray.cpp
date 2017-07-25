#include<bits/stdc++.h>
using namespace std;

int n,m,x,a[10],ans[200010],l,r;

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		if(x==1) a[1]++;
		else a[2]++;
	}
	int mins = min(a[2],a[1]);
	//cout<<mins<<endl;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&l,&r);
		x = r-l+1;
	//	cout<<x<<endl;
		if((x%2==0 )&& ((x/2)<=mins)) ans[i] = 1;
		else ans[i] = 0;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<endl;
}
