#define fi first
#define se second
#include<bits/stdc++.h>
using namespace std;

int n;
pair<int,pair<int,int> > arr[500005];
priority_queue<pair<int,int> > pq;
bool dipake[500005];

bool komp(pair<int,pair<int,int> > x, pair<int,pair<int,int> > y) {
	return x>=y;
}

int main() {
	memset(dipake, false, sizeof dipake);
	scanf("%d",&n);
	for (int i=0; i<n; i++) {
		scanf("%d",&arr[i].fi);
	}
	for (int i=0; i<n; i++) {
		scanf("%d",&arr[i].se.fi);
		arr[i].se.se=i;
	}

	sort(arr,arr+n,komp);
	long long hasil=0;

	for (int i=n-1; i>=0; i--) {
		pq.push(arr[i].se);

		if (i%2 == 1) {
			pair<int,int> ambil = pq.top();
			pq.pop();
			dipake[ambil.se] = true;
			hasil += ambil.fi;	
		}
		
	}

	while(!pq.empty()) { pq.pop(); }

	for (int i = 0; i < n; i++) { cout << dipake[i] << " "; }

	cout<<hasil<<endl;
	bool lagii=true;
	int ii=0,jj=0;
	while (jj<n || ii<n) {
		if (lagii) {
			while (!dipake[arr[ii].se.se]) {
				ii++;
			}
			cout<<"["<<arr[ii].se.se+1<<"] "<<arr[ii].se.fi;
			lagii=false;
			ii++;
		} else {
			while (dipake[arr[jj].se.se]) {
				jj++;
			}
			cout<<"["<<arr[jj].se.se+1<<"]"<<arr[jj].fi<<endl;
			lagii=true;
			jj++;
		}
	}
}
