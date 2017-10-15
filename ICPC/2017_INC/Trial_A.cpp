// solution by Ensof Barhami
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll mod=1000000007;
ll n,x,dummy,minn=9999999999,maxx=-1,sum=0;
int main(){
	scanf("%lld",&n);
	while(n--){
		cin>>x;
		minn=min(x,minn);
		maxx=max(x,maxx);
		sum+=x;
	}
	for(int i=0;i<10;i++){
		if((i!=minn && i!=maxx) && i!=sum){
			cout<<i<<endl;
			return 0;
		}
	}

}