#include <bits/stdc++.h>
using namespace std;

int n;
string s;

int main() {
    getline(cin, s);
    cin >>n;
    n %= 26;
    while (n < 0) n += 26;

    for (int i = 0; i < s.length(); i++) {
        char cc = s[i];
        if ('a' <= cc && cc <= 'z') {
            printf("%c", (cc - 'a' + n) % 26 + 'a');
        }
        else if ('A' <= cc && cc <= 'Z') {
            printf("%c", (cc - 'A' + n) % 26 + 'A');
        } else {
            printf("%c", cc);
        }
    }
    printf("\n");
}