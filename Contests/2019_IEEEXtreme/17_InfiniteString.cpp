#include <bits/stdc++.h>
using namespace std;

void solve() {
    int b; long long x;
    scanf("%d%lld", &b, &x);
    if (b == 1) {
        cout << "a" << endl;
        return;
    }
    int len = 1;
    long long cnt = b;
    while (x / len >= cnt) {
        x -= cnt * len;
        len++;
        cnt *= b;
    }

    cnt /= b;
    long long num = x / len;
    int kar = x % len;

    string s = "";
    while (cnt > 0) {
        s += (num / cnt + 'a');
        num %= cnt;
        cnt /= b;
    }
    cout << s[kar] << endl;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        solve();
    }
}