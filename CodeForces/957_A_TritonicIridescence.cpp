#include <cstdio>
#include <iostream>
using namespace std;

int main() {
  int n;
  string s;
  scanf("%d", &n);
  cin >> s;
  for (int i=1; i<n; i++) {
    if (s[i] == s[i-1] && s[i] != '?') {
      printf("No\n");
      return 0;
    }
  }
  bool ada = false;
  for (int i=2; i<n; i++) {
    if (s[i] != '?' && s[i-1] == '?' && s[i-2] != '?') {
      if (s[i] == s[i-2]) ada = true;
    }
  }
  for (int i=1; i<n; i++) {
    if (s[i] == '?' && s[i-1] == '?') {
      ada = true;
    }
  }
  if (s[0] == '?' || s[s.length()-1] == '?') ada =true;
  if (ada) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
}