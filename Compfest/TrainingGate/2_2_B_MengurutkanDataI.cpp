/**
 * Solution by: Restu Wayu Kartiko
 */

#include <bits/stdc++.h>
using namespace std;

int n,a[1001];

int main(){
  cin>>n;
  for(int i=0;i<n;i++) scanf("%d",&a[i]);
  sort(a,a+n);
  for(int i=0;i+1<n;i++) cout<<a[i]<<" ";
  cout<<a[n-1]<<endl;
}