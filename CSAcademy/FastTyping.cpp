#include <cstdio>
#include <iostream>
using namespace std;

string s;
int v[30];
int sum=0;

int main() {
  cin >> s;
  for (int i=0; i<26; i++) {
    cin >> v[i];
  }
  for (int i=0; i<s.length(); i++) {
    sum += v[s[i]-'a'];
  }
  cout << sum << endl;
}