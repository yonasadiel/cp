#include <bits/stdc++.h>
#define ll long long
using namespace std;

string s;

int solve() {
    string t;
    int l = (s.length() - 1) / 2;
    int r = l + 1;
    while (true) {
        if (l >= 0) {
            printf("%c", s[l]);
            l--;
        } else break;
        if (r < s.length()) {
            printf("%c", s[r]);
            r++;
        } else break;
    }
    printf("\n");
}

int main() {
    while (cin >> s) {
        solve();
    }
}