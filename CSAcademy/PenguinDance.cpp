#include <iostream>

using namespace std;

int main() {
    int n, p, t;
    cin >> n >> p >> t;
    int x = p - 3 * (t/9);
    if (t%9 == 5) x--;
    if (t%9 == 7) x--;
    if (t%9 == 8) x -= 2;
    if (x >= 1 && x <= n) {
      cout << x << endl;
    } else {
      cout << -1 << endl;
    }
}