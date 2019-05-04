#include <bits/stdc++.h>
using namespace std;

int main() {
    string n;
    int t;
    cin >> t;
    for (int i=1; i<=t; i++) {
        cin >> n;
        cout << "Case #" << i << ": ";
        for (char c : n) {
            if (c == '4') {
                cout << '3';
            } else {
                cout << c;
            }
        }
        cout << ' ';
        bool already = false;
        for (char c : n) {
            if (c == '4') {
                cout << '1';
                already = true;
            } else if (already) {
                cout << '0';
            }
        }
        cout << endl;
    }
}