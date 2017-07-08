#include<bits/stdc++.h>
using namespace std;

int n,m;
int arr[100500];
int brr[100500];
int bisa[100500];

void check(int mid) {
	queue<int>antri;
	int sudah[100050];
	memset(sudah,-1,sizeof sudah);
	for (int i=mid; i>0; i--) {
		if (arr[i]!=0) {
			if (sudah[arr[i]]==-1) {
				antri.push(arr[i]);
				sudah[arr[i]]=brr[arr[i]];
			} else if (!antri.empty()) {
				sudah[antri.front()]--;
				if (sudah[antri.front()] == 0) {
					antri.pop();
				}	
			}
		} else if (!antri.empty()) {
			sudah[antri.front()]--;
			if (sudah[antri.front()] == 0) {
				antri.pop();
			}
		}
	}
	bool ans=true;
	for (int i=1; i<=m; i++) {
		if (sudah[i] != 0) ans=false;
	}
	if (!antri.empty()) ans=false;
	while(!antri.empty()) antri.pop();
	
	if (ans) {
		bisa[mid]=1;
	} else {
		bisa[mid]=-1;
	}
	/*
	cout<<"bisa ";
	for (int i=1; i<=m; i++) {
		cout<<bisa[i]<<" ";
	}cout<<endl;
	*/
}

int main() {
	scanf("%d%d",&n,&m);
	for (int i=1; i<=n; i++) {
		scanf("%d",&arr[i]);
	}
	for (int i=1; i<=m; i++) {
		scanf("%d",&brr[i]);
	}
	
	memset(bisa,0,sizeof bisa);
	
	int mini=1,maks=n,mid;
	while (mini<=maks) {
		mid=(mini+maks)/2;
		if (mid < 0) {
			printf("error 1"); return 0;
		}
	//	cout<<mini<<" "<<maks<<" "<<mid<<endl;
		if (bisa[mid]==0) check(mid);
		if (bisa[mid-1]==0) check(mid-1);
		if ((bisa[mid]==1 && bisa[mid-1]==-1)) break;
		if (bisa[mid]==1)  {
			maks=mid-1;
//			cout<<" pushing maks"<<endl;
		} else {
			mini=mid+1;
//			cout<<" pusing min"<<endl;
		}
	}
	if (mini<=maks)printf("%d\n",mid);
	else printf("-1\n");
//	for(int i=1; i<=n; i++) {
//		cout<<bisa[i]<<" ";
//	}cout<<endl;
}
