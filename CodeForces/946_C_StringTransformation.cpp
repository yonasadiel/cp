#include <cstdio>
#include <iostream>
using namespace std;

int main() {
  string s;
  cin >> s;
  char cur= 'a';
  for (int i=0; i<s.length() && cur <= 'z'; i++) {
    if (s[i] <= cur) { s[i] = cur; cur++; }
  }
  if (cur == 'z'+1) {
    cout << s<< endl;
  } else {
    cout << -1 << endl;
  }
}