#include<bits/stdc++.h>
using namespace std;

string n;

int main() {
  cin>>n;
  long long cnt=0;
  int l=n.length();
  if (n[l-1]=='4' || n[l-1]=='0' || n[l-1]=='8') {
    cnt++;
  }
  for (int i=l-2; i>=0; i--) {
    if (n[i]=='0' || n[i]=='4' || n[i]=='8') {
      cnt++;
    }
    if (((n[i]-'0')*10+(n[i+1]-'0'))%4 == 0) {
      cnt+=i+1;
    }
  }
  printf("%I64d\n",cnt);
}
