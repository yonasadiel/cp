#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int n;
  string s;
  scanf("%d\n",&n);
  getline(cin, s);
  int ret = 0;
  int tmp = 0;
  for (int i=0; i<n; i++) {
    if (s[i] == ' ') { ret = max(tmp, ret); tmp = 0; }
    if (s[i] >= 'A' && s[i] <= 'Z') { tmp++; }
  } ret = max(tmp, ret);
  printf("%d\n", ret);
}