#include <cstdio>
#include <iostream>
using namespace std;

bool isVowel(char s) {
  return
    s == 'a' || s == 'e' || s == 'u' ||
    s == 'o' || s == 'i' || s == 'y';
}

int main() {
  int n;
  string s;

  cin >> n >> s;
  for (int i=0; i<n; i++) {
    if (!isVowel(s[i]) || i == 0 || !isVowel(s[i-1])) {
      cout << s[i];
    }
  }
  cout << endl;
}