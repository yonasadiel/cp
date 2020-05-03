#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i=1; i<=t; i++) {
        int n;
        string s;
        cin >> n;
        cin >> s;
        cout << "Case #" << i << ": ";
        for (char c : s) {
            if (c == 'E') cout << 'S';
            else cout << 'E';
        }
        cout << endl;
    }
}