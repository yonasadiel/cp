#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
using namespace std;

ll r, c, a, b, x, y;

int main() {
    scanf("%lld%lld%lld%lld%lld%lld", &r, &c, &a, &b, &x, &y);
    if (x >= a) {
        if (a % 2 == x % 2) {
            if ((b % 2 == y % 2) && (b-(x-a) <= y) && (y <= b+(x-a))) {
                cout << "YA" << endl;
            } else {
                cout << "TIDAK" << endl;
            }
        } else {
            if ((b % 2 != y % 2) && (b-(x-a) <= y) && (y <= b+(x-a))) {
                cout << "YA" << endl;
            } else {
                cout << "TIDAK" << endl;
            }
        }
    } else {
        cout << "TIDAK" << endl;
    }
}