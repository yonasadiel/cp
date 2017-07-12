/**
 * Solution by: Restu Wayu Kartiko
 */

#include <bits/stdc++.h>
using namespace std;

int n,x;
string s;
queue < string > q;

int main(){
  cin>>n;
  for(int i=1;i<=n;i++){
    scanf("%d",&x);
    if(x == 1){
      cin>>s;
      q.push(s);
    }
    else if(x == 2 && !q.empty()){
      cout<<q.front()<<endl;
      q.pop();
    }
  }
}