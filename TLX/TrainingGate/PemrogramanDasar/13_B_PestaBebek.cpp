#include<bits/stdc++.h>
using namespace std;

int n;
string arr[1005];
string temp;

int main() {
	scanf("%d",&n);
	for (int i=0; i<n; i++) {
		cin>>arr[i];
		temp = arr[i];
		sort(arr,arr+i+1);
		for (int j=0; j<=i; j++) {
			if (temp==arr[j]) cout<<j+1<<endl;
		}
	}
	
}
