#include<bits/stdc++.h>
using namespace std;              

int main() {
	int n,a;
	int ar[5]={0,0,0,0,0};
	scanf("%d",&n);
	while (n--) {
		scanf("%d",&a);
		ar[a]++;
	}
	if (ar[1]+ar[2]*2+ar[3]*3+ar[4]*4<3 || ar[1]+ar[2]*2+ar[3]*3+ar[4]*4==5) {
		cout<<-1<<endl;
		return 0;
	}
	if (ar[1]==1 && ar[2]==0 && ar[3]==0 && ar[4]>0) {
		cout<<2<<endl;
		return 0;
	}
//	cout<<ar[0]<<" "<<ar[1]<<" "<<ar[2]<<" "<<ar[3]<<" "<<ar[4]<<endl;
	if (ar[1]>ar[2]) {
		int res=0;
		res+=ar[2]; ar[1]-=ar[2]; ar[3]+=ar[2]; ar[2]=0;
//		cout<<ar[0]<<" "<<ar[1]<<" "<<ar[2]<<" "<<ar[3]<<" "<<ar[4]<<" "<<res<<endl;
		res+=ar[1]-ar[1]/3;
		cout<<res<<endl;
	} else {
		int res=0;
		res+=ar[1]; ar[2]-=ar[1]; ar[3]+=ar[1]; ar[1]=0;
		if (ar[2]%3!=0) {
			if (ar[4]<ar[2]%3) {
				res+=(ar[2]/3+1)*2;
				cout<<res<<endl;
				return 0;
			} else {
				res+=ar[2]%3; ar[3]+=ar[2]%3; ar[4]-=ar[2]%3; ar[2]-=ar[2]%3; 	
			}
		}
		res+=ar[2]*2/3;
		cout<<res<<endl;
	}
}
