#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int> > v;

int main() {
    scanf("%d", &n);
    int a = 1;

    v.assign(n, vector<int>());
    for (int i = 0; i < n; i++) {
        if (i & 1) {
            for (int j = 0; j < n; j++) {
                v[j].push_back(a);
                a++;
            }
        } else {
            for (int j = n - 1; j >= 0; j--) {
                v[j].push_back(a);
                a++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d%c", v[i][j], j == n - 1 ? '\n' : ' ');
        }
    }
}