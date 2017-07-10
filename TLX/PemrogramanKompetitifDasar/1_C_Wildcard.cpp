#include<bits/stdc++.h>
using namespace std;

int main() {
  string sget,sinp;
  int n,ind,sgetl;

  cin>>sget>>n;
  sgetl = sget.length();
  for (int i=0; i<sgetl; i++) {
    if (sget[i] == '*') {
      ind = i;
    }
  }

  for (int i=0; i<n; i++) {
    cin>>sinp;
    bool benar=true;
    for (int j=0; j<ind; j++) {
      if (sinp[j] != sget[j]) benar = false;
    }
    for (int j=0; j<sgetl-1-ind; j++) {
      if (sinp[sinp.length()-1-j] != sget[sgetl-1-j]) benar=false;
    }
    if (benar && sgetl-1 <= sinp.length()) cout<<sinp<<endl;
  }



}
