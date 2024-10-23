#include<iostream>
#include<vector>
#include<cstdio>
#define ll long long
using namespace std;

vector<long long> mem;

void solve(int tc) {
    ll a, b, m;
    scanf("%lld%lld%lld", &a, &b, &m);
    int ans = 0;
    for(const long long& c : mem) {
        if (a <= c && c <= b && c % m == 0) {
            ans++;
        }
    }
    printf("Case #%d: %d\n", tc, ans);
}

int main() {
    for (int i=1; i<=9; i++) {
        for (int j=i; j<=9; j++) {
            long long c = 0;
            for (int k=i; k<=j; k++) { c *= 10; c += k; }
            for (int k=j-1; k>=i; k--) { c *= 10; c += k; }
            mem.push_back(c);
        }
    }
    int t;
    scanf("%d", &t);
    for (int i=1; i<=t; i++) solve(i);
}
