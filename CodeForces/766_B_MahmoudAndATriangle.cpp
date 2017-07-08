#include<bits/stdc++.h>
using namespace std;

int n;
int arr[100005];

int main() {
	scanf("%d",&n);
	for (int i=0; i<n; i++) {
		scanf("%d",&arr[i]);
	}
	sort(arr,arr+n);
	
	string fnd = "NO";
	for (int i=0; i+2<n; i++) {
		if (arr[i]+arr[i+1]>arr[i+2]) {
			fnd = "YES";
		}
	}
	cout<<fnd<<endl;
}
