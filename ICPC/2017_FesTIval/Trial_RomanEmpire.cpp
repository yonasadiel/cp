#include <cstdio>
#include <iostream>
using namespace std;

int toInt(string a){
  int r = 0;
  int last = 0;
  for (int i=a.length()-1; i>=0; i--) {
    int g = -1;
    if (a[i] == 'M') g = 1000;
    if (a[i] == 'D') g =  500;
    if (a[i] == 'C') g =  100;
    if (a[i] == 'L') g =   50;
    if (a[i] == 'X') g =   10;
    if (a[i] == 'V') g =    5;
    if (a[i] == 'I') g =    1;
    if (g < last) { r -= g; }
    else          { r += g; last = g; }
  }
  return r;
}

string toRN(int a){
  string r = "";
  while (a > 0) {
    if (a >= 1000) { r += "M" ; a-= 1000; continue; }
    if (a >=  900) { r += "CM"; a-=  900; continue; }
    if (a >=  500) { r += "D" ; a-=  500; continue; }
    if (a >=  400) { r += "CD"; a-=  400; continue; }
    if (a >=  100) { r += "C" ; a-=  100; continue; }
    if (a >=   90) { r += "XC"; a-=   90; continue; }
    if (a >=   50) { r += "L" ; a-=   50; continue; }
    if (a >=   40) { r += "XL"; a-=   40; continue; }
    if (a >=   10) { r += "X" ; a-=   10; continue; }
    if (a >=    9) { r += "IX"; a-=    9; continue; }
    if (a >=    5) { r += "V" ; a-=    5; continue; }
    if (a >=    4) { r += "IV"; a-=    4; continue; }
    if (a >=    1) { r += "I" ; a-=    1; continue; }
  }
  return r;
}

string hitung(string a, string b){
  int da = toInt(a);
  int db = toInt(b);

  return toRN(da+db);
}

int main(){
  int t;
  string a,b;

  scanf("%d",&t);
  for (int t_i=1; t_i<=t; t_i++) {
    cin >> a;
    cin >> b;

    cout << "Case #" << t_i << ": " << hitung(a,b) << "\n";
  }
}