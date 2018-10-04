#include <bits/stdc++.h>
using namespace std;

int n,m, x;
int a[2005];
int b[2005];
vector<pair<int, int> > allb;
vector<int> allb2;
vector<int> rangeb;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first != b.first)
        return a.first < b.first;
    return a.second > b.second;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i=0; i<n; i++) { scanf("%d", &a[i]); }
    for (int i=0; i<m; i++) { scanf("%d", &b[i]); }
    scanf("%d", &x);

    for (int i=0; i<m; i++) {
        int sum = 0;
        for (int j=i; j<m; j++) {
            sum += b[j];
            allb.push_back(make_pair(sum, j - i + 1));
        }
    }
    sort(allb.begin(), allb.end(), cmp);

    int last = 0;
    for (auto aa : allb) {
        last = max(last, aa.second);
        rangeb.push_back(last);
        allb2.push_back(aa.first);
    }

    int ans = 0;
    for (int i=0; i<n; i++) {
        int sum = 0;
        for (int j=i; j<n; j++) {
            sum += a[j];

            int bi = upper_bound(allb2.begin(), allb2.end(), x / sum) - allb2.begin() - 1;

            if (bi >= 0 && bi < rangeb.size()) {
                ans = max(ans, (j - i + 1) * rangeb[bi]);
            }
        }
    }
    printf("%d\n", ans);
}