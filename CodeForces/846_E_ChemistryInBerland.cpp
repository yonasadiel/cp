#include <bits/stdc++.h>
using namespace std;

int n;
long double b[100005];
long double a[100005];
long double y[100005];
int parent[100005];
int child[100005];

int main() {
    memset(child, 0, sizeof child);
    parent[0] = 0;
    scanf("%d", &n);
    for (int i=0; i<n; i++) { scanf("%Lf", &b[i]); }
    for (int i=0; i<n; i++) { scanf("%Lf", &a[i]); }
    for (int i=1; i<n; i++) {
        scanf("%d%Lf", &parent[i], &y[i]);
        parent[i]--; // change to zero based
        child[parent[i]]++;
    }

    queue<int> q;

    for (int i=0; i<n; i++) {
        if (child[i] == 0) {
            q.push(i); // push all leaves
        }
    }

    while (!q.empty()) {
        int top = q.front(); q.pop();

        long double x = b[top] - a[top];
        if (parent[top] != top) {
            if (x > 0) {
                b[parent[top]] += x;
            } else if (x < 0) {
                if (llabs(y[top]) > llabs(1e17 / x)) {
                    printf("NO\n");
                    return 0;
                }
                b[parent[top]] += x * y[top];
            }

            child[parent[top]]--;
            if (child[parent[top]] == 0) {
                q.push(parent[top]);
            }
        }
    }

    if (b[0] >= 0) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}