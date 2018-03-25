#include <iostream>
#include <cstdio>
using namespace std;

int main() {
  string a,b;
  cin >> a >> b;
  if (a.length() != b.length()) { printf("NO\n"); }
  else {
    for (int i=0; i<a.length(); i++) {
      if (a[i] != b[b.length()-1-i]) {
        printf("NO\n");
        return 0;
      }
    }
    printf("YES\n");
  }
}