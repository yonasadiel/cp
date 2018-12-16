#include <bits/stdc++.h>
using namespace std;

int n;
string s;

int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> s;
        string s3 = s;
        string s2 = s;
        bool bisa = false;
        for (int j=0; j<s.length(); j++) {
            s2[j] = s[s.length() - j - 1];
        }
        for (int j=1; j<s.length(); j++) {
            if (!bisa && s[j] != s[0]) {
                s3[j] = s[0];
                s3[0] = s[j];
                bisa = true;
            }
        }

        if (s2 != s) {
            cout << s << endl;
        } else if (bisa) {
            cout << s3 << endl;
        } else {
            cout << -1 << endl;
        }
    }
}
