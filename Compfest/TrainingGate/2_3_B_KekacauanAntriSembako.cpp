/**
 * Solution by: Restu Wayu Kartiko
 */

#include <bits/stdc++.h>
using namespace std;

int n,x;
string s;
deque < string > q;

int main(){
  cin>>n;
  for(int i=1;i<=n;i++){
    scanf("%d",&x);
    if(x == 1 || x == 2){
      cin>>s;
      x == 1 ? q.push_front(s) : q.push_back(s);
    }
    else{
      if(x == 3){
        cout<<q.front()<<endl;
        q.pop_front();
      }
      else{
        cout<<q.back()<<endl;
        q.pop_back();
      }
    }
  }
}