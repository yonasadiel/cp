/**
 * Solution by: Restu Wayu Kartiko
 */

#include <bits/stdc++.h>
#define p push
using namespace std;

int n;
string s;

int main(){
  cin>>n;
  for(int i=1;i<=n;i++){
    stack < char > st;
    cin>>s;
    bool cek = true;
    for(int i=0;i<s.length();i++){
      if(st.empty() || s[i] == '(' || s[i] == '[')st.p(s[i]);
      else{
        char b = st.top();
//        cout<<b<<endl;
        if((b=='(' && s[i]==')') || (b=='[' && s[i]==']'))
          st.pop();
        else st.p(s[i]);
      }
    }
    if(st.empty())cout<<"ya"<<endl;
    else cout<<"tidak"<<endl;
  }
}