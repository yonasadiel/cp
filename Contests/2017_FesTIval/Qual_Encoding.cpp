#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

char trans(int l) {
  if (l < 26) return 'A' + l;
  if (l < 52) return 'a' + l - 26;
  if (l < 62) return '0' + l - 52;
  if (l == 62) return '+';
  if (l == 63) return '/';
  return '*';
}

void main_per_case(int kasus){
  string encd, decd;
  cin >> encd;
  for (int i=0; i<encd.length(); i+=6) {
    int r = 0;
    int l = 1;
    for (int j=i+5; j>=i; j--) {
      if (encd[j] == '1') { r += l; }
      //cout << encd[j] << endl;
      l *= 2;
    }
    //cout << r << endl;
    decd += trans(r);
  }
  cout << "Case #" << kasus << ": " << decd << endl;
}

int main(){
  int t;
  scanf("%d",&t);
  for (int t_i=1; t_i<=t; t_i++) {
    main_per_case(t_i);
  }
}