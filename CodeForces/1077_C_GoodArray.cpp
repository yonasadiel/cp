#include <bits/stdc++.h>
using namespace std;

int n;
pair<long long, int> a[200005];
long long sum = 0;

int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%lld", &a[i].first);
        sum += a[i].first;
        a[i].second = i;
    }

    sort(a, a + n);

    vector<int> ans;
    for (int i=0; i<n; i++) {
        if (a[i].first != a[n-1].first) {
            if (sum - a[i].first - a[n-1].first == a[n-1].first) {
                ans.push_back(a[i].second);
            }
        } else {
            if (sum - a[i].first - a[n-2].first == a[n-2].first) {
                ans.push_back(a[i].second);
            }
        }
    }

    printf("%d\n", ans.size());
    for (int i=0; i<ans.size(); i++) {
        printf("%d%c", ans[i] + 1, (i == ans.size()-1 ? '\n' : ' '));
    }
}