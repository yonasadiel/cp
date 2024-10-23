#include<iostream>
#include<vector>
#include<cstdio>
#define ll long long
using namespace std;

vector<long long> mem;

void run(int d, int i, long long c) {
    // cout << d << " " << i << " " << c << endl;
    if (i == d) { mem.push_back(c); return; }
    if (i < d/2) {
        for (int j=max(c%10, 1LL); j<9; j++) {
            run(d, i+1, c*10+j);
        }
        return;
    }
    if (i > d/2) {
        for (int j=1; j<c%10; j++) {
            run(d, i+1, c*10+j);
        }
        if (i > d/2+1) {
            run(d, i+1, c*10+c%10);
        }
        return;
    }
    if (i == d/2) {
        for (int j=(c%10)+1; j<10; j++) {
            run(d, i+1, c*10+j);
        }
        return;
    }
}

string aa, bb;
ll m;

void solve(int tc) {
    ll a, b;
    scanf("%lld%lld%lld", &a, &b, &m);
    int i = lower_bound(mem.begin(), mem.end(), a) - mem.begin();
    int ans = 0;
    for (; i < mem.size() && mem[i] <= b; i++) {
        ans += (mem[i] % m == 0);
    }
    printf("Case #%d: %d\n", tc, ans);
}

int main() {
    for (int d=1; d<=17; d+=2) {
        run(d, 0, 0);
        // printf("%d %d\n", d, mem.size());
    }
    // for (int i=0; i< 100; i++)
    //     printf("%lld\n", mem[i]);
    sort(mem.begin(), mem.end());
    int t;
    scanf("%d", &t);
    for (int i=1; i<=t; i++) solve(i);
}
