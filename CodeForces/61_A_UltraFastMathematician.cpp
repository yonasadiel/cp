#include <cstdio>
#include <iostream>
using namespace std;

string a,b;

int main() {
  cin >> a >> b;
  for (int i=0; i<a.length(); i++) {
    if (a[i] == '0' && b[i] == '1') printf("1");
    else if (a[i] == '1' && b[i] == '0') printf("1");
    else printf("0");
  }
  printf("\n");
}