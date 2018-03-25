#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n;
string s;
bool ada[256];

int main() {
  memset(ada, false, sizeof ada);

  scanf("%d",&n);
  cin >> s;
  for (int i=0;i<n; i++) {
    ada[s[i]] = 1;
  }

  bool pangram = true;
  for (int i=0; i<26; i++) {
    if (!ada['a'+i] && !ada['A'+i]) {
      pangram = false;
    }
  }
  printf("%s\n", (pangram)? "YES":"NO");
}