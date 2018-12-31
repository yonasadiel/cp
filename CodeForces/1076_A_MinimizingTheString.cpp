#include <bits/stdc++.h>
using namespace std;

int n;
string s;

int main() {
    cin >> n;
    cin >> s;
    char lama = s[0];
    int potong = s.length()-1;
    for (int i=1; i<s.length(); i++) {
        if (s[i] < s[i-1]) {
            potong = i-1;
            break;
        }
    }
    for (int i=0; i<potong; i++) printf("%c", s[i]);
    for (int i=potong+1; i<s.length(); i++) printf("%c", s[i]);
    printf("\n");
}