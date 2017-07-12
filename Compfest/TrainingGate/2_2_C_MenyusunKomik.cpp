/**
 * Solution by: Restu Wayu Kartiko
 */

#include <bits/stdc++.h>
using namespace std;

int n,a[1010],ans,ind;

int main(){
  cin>>n;
  for(int i=1;i<=n;i++) cin>>a[i];
  for(int i=n;i>0;i--){
    int maks = 0;
    for(int j=1;j<=i;j++){
      if(maks < a[j]){
        maks = a[j];
        ind = j;
      }
    }
    if(ind != i){
      ans++;
      swap(a[ind],a[i]);
    }
  }
  cout<<ans<<endl;
}