#include <bits/stdc++.h>
using namespace std;

int n, k;
string s;

int main() {
    cin >> n >> k;
    cin >> s;
    int ans = 0;
    for (char cc = 'a'; cc <= 'z'; cc++) {
        int temp = 0;
        int cnt = 0;
        for (int i=0; i<s.length(); i++) {
            if (s[i] == cc) {
                cnt++;
            } else {
                cnt = 0;
            }
            if (cnt == k) {
                cnt = 0;
                temp++;
            }
        }
        ans = max(ans, temp);
    }
    printf("%d\n", ans);
}