#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int s[200];

void solve(int tc) {
    memset(s, 0, sizeof(s));
    int n, k, x;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        s[x]++;
    }
    bool bisa = n <= k * 2;
    for (int i = 1; i <= 100; i++) {
        if (s[i] > 2) bisa = false;
    }
    cout << "Case #" << tc << ": " << (bisa ? "YES" : "NO") << endl;
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) solve(i);
}