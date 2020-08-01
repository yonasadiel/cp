#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  string a;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    cin >> a;
  }
  int x, s = 0;
  for (int i =0; i<n; i++) {
    cin >> x;
    s += x;
  }
  for (int i = 0; i < n-1; i++) {
    cin >> x;
    s -= x;
  }
  cout << s << endl;
}
