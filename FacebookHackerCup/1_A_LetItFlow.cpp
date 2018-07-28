#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

int n;
char grid[3][1000];

void solve(int tc) {
    scanf("%d\n", &n);
    scanf("%s\n", grid[0]);
    scanf("%s\n", grid[1]);
    scanf("%s\n", grid[2]);
    ll a=1, b=0, c=0;
    for (int i=0; i<n; i++) {
        ll aa=0, bb=0, cc=0;
        if (grid[0][i] != '#' && grid[1][i] != '#') {
            aa += b;
            bb += a;
        }
        if (grid[1][i] != '#' && grid[2][i] != '#') {
            bb += c;
            cc += b;
        }
        aa %= MOD, bb %= MOD, cc %= MOD;
        a = aa, b = bb, c = cc;
    }
    printf("Case #%d: %lld\n", tc, c);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i=1; i<=t; i++) {
        solve(i);
    }
}