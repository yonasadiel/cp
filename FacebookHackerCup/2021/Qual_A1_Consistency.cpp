#include <iostream>
using namespace std;

int n;
string s;

bool is_vowel(char cc) {
    return cc == 'A' || cc == 'E' || cc == 'I' || cc == 'O' || cc == 'U';
}

void solve(int tc) {
    cin >> s;
    int ans = 1000000;
    for (char tt = 'A'; tt <= 'Z'; tt++) {
        int temp = 0;
        for (char cc : s) {
            if (cc == tt) continue;
            if (is_vowel(cc) ^ is_vowel(tt)) temp += 1;
            else temp += 2;
        }
        if (ans > temp) {
            ans = temp;
        }
    }
    cout << "Case #" << tc << ": " << ans << endl;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        solve(i+1);
    }
}