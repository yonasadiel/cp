#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

pii a[100005];

bool comp(pii a, pii b) {
    if (a.first == b.first) {
        return a.second > b.second;
    }
    return a.first < b.first;
}

void solve(int tc) {
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        a[i].first = x-y;
        a[i].second = x+y;
    }

    sort(a, a+n, comp);

    int cnt = 0;
    int left = -10000000;
    int right = -10000000;
    for (int i=0; i<n; i++) {
        if ((left <= a[i].first  && a[i].first  <= right) ||
            (left <= a[i].second && a[i].second <= right)) {
            left = max(left, a[i].first);
            right = min(right, a[i].second);
        } else {
            cnt++;
            left = a[i].first;
            right = a[i].second;
        }
    }

    printf("Kasus #%d: %d\n", tc, cnt);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i=1; i<=t; i++) {
        solve(i);
    }
}