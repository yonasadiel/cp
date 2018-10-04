#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, cnt=0;
    string s;

    cin >> n;
    cin >> s;
    for (int i=0; i<s.length(); i++) {
        if (s[i] == '8') {
            cnt++;
        }
    }
    cout << min(n/11, cnt) << endl;
}