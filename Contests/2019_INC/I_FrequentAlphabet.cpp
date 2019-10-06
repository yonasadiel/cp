#include <bits/stdc++.h>
using namespace std;

int n;
char s[100005];
char t[100005];

int main() {
    scanf("%d", &n);
    scanf("%s", s);
    scanf("%s", t);

    int ans = 0;
    for (char cc = 'a'; cc <= 'z'; cc++) {
        int temp = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == cc || t[i] == cc) {
                temp++;
            }
        }
        ans = max(ans, temp);
    }
    printf("%d\n", ans);

}