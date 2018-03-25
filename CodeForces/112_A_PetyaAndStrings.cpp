#include <cstdio>
#include <iostream>
using namespace std;

string a,b;

string tolower(string s) {
  for (int i=0; i<s.length(); i++) {
    if (s[i] >= 'A' && s[i] <= 'Z') s[i] = s[i] - 'A' + 'a';
  }
  return s;
}

int main() {
  cin >> a >> b;
  a = tolower(a);
  b = tolower(b);
  if (a < b) { printf("-1\n"); }
  else if (a == b) { printf("0\n"); }
  else { printf("1\n"); }

}