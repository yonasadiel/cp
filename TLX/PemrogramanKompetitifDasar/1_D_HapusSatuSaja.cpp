#include<bits/stdc++.h>
using namespace std;

int main() {
  string s1,s2;
  cin>>s1>>s2;
  bool bisa = true;
  if (s1.length() == s2.length() + 1) {
    int sudah = 0;
    for (int i=0; i+sudah<s1.length(); ) {
      if (s1[i+sudah] != s2[i] && sudah == 0) {
        sudah = 1;
      } else if (s1[i+sudah] != s2[i] && sudah == 1) {
        bisa = false;
        break;
      } else {
        i++;
      }
    }
  } else {
    bisa = false;
  }

  if (bisa) {
    cout<<"Tentu saja bisa!"<<endl;
  } else {
    cout<<"Wah, tidak bisa :("<<endl;
  }
}
