#include <iostream>
#include <algorithm>
using namespace std;

string a,b, c[12];

int main() {
  cin >> a >> b;

  for (int i=0; i<a.length(); i++) {
    for (int j=0; j<a.length()-i; j++) {
      if (i == 0) c[j] = "";
      c[j] += a[i];
    }
  }
  for (int j=0; j<a.length(); j++) {
    c[j] += b[0];
  }

  sort(c, c+a.length());
  cout << c[0] << endl;
}