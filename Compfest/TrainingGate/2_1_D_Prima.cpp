/**
 * Solution by: Restu Wayu Kartiko
 */

#include <bits/stdc++.h>
using namespace std;

int n,k,prim[100000];
bool bol[1000100];

void sieve(){
  memset(bol,true,sizeof(bol));
  int ind = 0;
  for(int i=2;i<=sqrt(1000000);i++)
    if(bol[i])
      for(int j=i*2;j<=1000000;j+=i) bol[j] = false;
  for(int i=2;i<=1000000;i++)
    if(bol[i]) prim[++ind] = i;
}

int main(){
  sieve();
  cin>>n>>k;
  cout<<prim[1]<<endl;
  for(int i=1;i<n;i++) cout<<prim[i*k+1]<<endl;
}