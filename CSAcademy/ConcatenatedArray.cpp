#include <iostream>
#include <algorithm>
using namespace std;

string s;
int n,k;

int main() {
  cin >> n >> k;
  cin >> s;
  long long cnt = 0, maxcnt = 0;

  for (int i=0; i<min(2,k)*n; i++) {
    if (s[i%n] == '0') {
      cnt++;
      maxcnt = max(maxcnt,cnt);
    } else {
      cnt = 0;
    }
  }
  if (maxcnt == (long long) 2*n) {
    maxcnt = (long long) n*k;
  }

  cout << maxcnt << endl;
}