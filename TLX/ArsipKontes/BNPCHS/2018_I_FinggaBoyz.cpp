#include <bits/stdc++.h>
using namespace std;

vector<int> ans;
int a[200];
bool taken[200];

void solve(int tc) {
    int n, k;
    ans.clear();
    scanf("%d%d", &n, &k);
        memset(taken, false, sizeof taken);
    for (int i=1; i<=n; i++) {
        for (int j=0; j<i; j++) {
            scanf("%d", &a[j]);
        }
        sort(a, a+i);
        int tans = -1;
        for (int j=0; j<i; j++) {
            if (!taken[a[j]]) {
                taken[a[j]] = true;
                tans = a[j];
                break;
            }
        }
        if (tans == -1) {
            printf("Kasus #%d: Tidak ada pembagian\n", tc);
            return;
        }
        ans.push_back(tans);
    }
    printf("Kasus #%d:", tc);
    for (int i=0; i<n; i++) {
        printf(" %d", ans[i]);
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