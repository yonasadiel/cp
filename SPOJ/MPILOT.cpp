#include <bits/stdc++.h>
using namespace std;

int arr[10005];

int main() {
    int n, x, y, ans = 0;

    scanf("%d",&n);
    for (int i=n-1; i>=0; i--) {
        scanf("%d%d", &x, &y);
        arr[i] = x-y; // salary addition if promoted to captain
        ans += y;
    }

    priority_queue<int> pq;

    ans += arr[0];
    for (int i=1; i<n; i++) {
        pq.push(-arr[i]);
        if (i%2 == 0) {
            ans += -pq.top();
            pq.pop();
        }
    }

    printf("%d\n", ans);
}