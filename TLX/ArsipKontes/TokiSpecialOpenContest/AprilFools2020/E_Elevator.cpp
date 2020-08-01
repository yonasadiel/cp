#include <bits/stdc++.h>
using namespace std;

set<string> name;
set<int> f;

int main() {
  int n, m, x, a;
  string s;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> a;
    for (int j = 0; j < a; j++) {
      cin >> s;
      name.insert(s);
    }
    for (int j = 0; j < a; j++) {
      cin >> x;
      f.insert(x);
    }
  }
  bool o = true;
  for (auto it = name.begin(); it != name.end(); it++) {
    if (!o) cout << " ";
    o = false;
    cout << *it;
  }
  cout << endl;
  o = true;
  for (auto it = f.begin(); it != f.end(); it++) {
    if (!o) cout << " ";
    o = false;
    cout << *it;
  }
}