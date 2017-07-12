/**
 * Solution by: Restu Wayu Kartiko
 */

#include<bits/stdc++.h>
using namespace std;

int n,a[1001],m,x;

int main(){
  cin>>n>>m;
  for(int i=0;i<n;i++) scanf("%d",&a[i]);
  sort(a,a+n);
  for(int i=1;i<=m;i++){
    scanf("%d",&x);
    cout<<a[x-1]<<endl;
  }
}