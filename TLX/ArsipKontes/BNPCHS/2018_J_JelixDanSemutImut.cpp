#include <bits/stdc++.h>
using namespace std;

int a[100005];
int r[100005];
int l[100005];

void solve(int tc) {
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    printf("Kasus #%d:", tc);
    stack<int> s;
    for (int i=0; i<n;) {
        if (s.empty() || a[i] < a[s.top()]) {
            s.push(i);
            i++;
        } else {
            r[s.top()]  = i;
            s.pop();
        }
    }
    while (!s.empty()) {
        r[s.top()] = n;
        s.pop();
    }

    for (int i=n-1; i>=0;) {
        if (s.empty() || a[i] < a[s.top()]) {
            s.push(i);
            i--;
        } else {
            l[s.top()]  = i;
            s.pop();
        }
    }
    while (!s.empty()) {
        l[s.top()] = -1;
        s.pop();
    }

    for (int i=0; i<n; i++) {
        printf(" %d", r[i] - i - 1 + i - l[i] - 1);
    }
    printf("\n");
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i=1; i<=t; i++) {
        solve(i);
    }
}