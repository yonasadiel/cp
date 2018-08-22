#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int permut[10];

int main() {
    long long n, c, s, a[10], b[10];
    cin >> n >> c >> s;
    for (int i=0; i<n; i++) {
      cin >> a[i] >> b[i];
      permut[i] = i;
    }

    long long ans = (c +s-1) / s;
    //cout << ans << endl;

    do {
      long long val = 0;
      long long inc = s;
      long long t = 0;

      for (int i=0; i<n; i++) {
        //cout << " " << permut[i];
      } //cout << endl;

      for (int i=0; i<n; i++) {
        if (val >= a[permut[i]]) {
          val -= a[permut[i]];
          inc += b[permut[i]];
        } else {
          long long ts = (a[permut[i]]-val +inc-1) / inc;
          val += ts * inc - a[permut[i]];
          inc += b[permut[i]];
          t += ts;
        }
        ans = min(ans, t+(c-val +inc-1) / inc);
        //cout << ans << endl;
      }
    } while (next_permutation(permut, permut + n));
    cout << ans << endl;
}