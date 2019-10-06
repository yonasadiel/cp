#include <bits/stdc++.h>
using namespace std;

int n;
string s;

int solve() {
    cin >> s;
    for (int i=0, j=1; i<s.length(); i+=j, j++) {
        printf("%c", s[i]);
    }
    printf("\n");
}

int main () {
    while (scanf("%d", &n) == 1) {
        solve();
    }
}