#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
string s;

void solve(int tc) {
    cin >> n >> s;
    cout << "Case #" << tc << ":\n";
    for (int i = 1; i < n; i++) {
        cout << (s[0] == '-' ? '.' : '-');
        for (int j = 128; j > 0; j >>= 1) {
            if (i & j) {
                cout << "-";
            } else {
                cout << ".";
            }
        }
        cout << "\n";
    }
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) solve(i);
}