#include<bits/stdc++.h>
using namespace std;

int n,a[10000],bit[10000],q,tipe,kiri,kanan,idx,val;

void update(int idx, int val){
	if(idx>=n) return;
	bit[idx]+=val;
	update(idx+(idx&-idx),val);
}

int query(int kanan){
	if(kanan==0) return 0;
	return bit[kanan]+query(kanan-(kanan&(-kanan)));
}

int main(){
	//ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
	cout<<"sadf";
	int t;
	//memset(bit,0,sizeof(bit));
	cin>>t;
	while(t--){
        int n,u;
        cin>>n>>u;
        while(u--){
            int l,r,v;
            cin>>l>>r>>v;
            update(l,v);
            update(r+1,-1*v);
        }
        int q;
        cin>>q;
        while(q--){
            int idx;
            cin>>idx;
            cout<<query(idx)-query(idx-1)<<"\n";
        }
	}
}

