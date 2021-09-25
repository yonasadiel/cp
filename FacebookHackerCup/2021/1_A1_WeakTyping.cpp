#include <iostream>
#include <cstdio>
using namespace std;

int n;
char s[1000000];

int tr(char cc) {
    if (cc == 'X') return 1;
    if (cc == 'O') return 2;
    return 3;
}

void solve(int tc) {
    scanf("%d", &n);
    scanf("\n%s", s);

    int cc = tr(s[0]), ans = 0;
    for (int i = 1; i < n; i++) {
        int ci = tr(s[i]);
        if (cc & ci) {
            cc = cc & ci;
        } else {
            cc = ci;
            ans += 1;
        }
        // printf("%c%d ", s[i], cc);
    }
    printf("Case #%d: %d\n", tc, ans);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i=1; i<=t; i++) solve(i);
}