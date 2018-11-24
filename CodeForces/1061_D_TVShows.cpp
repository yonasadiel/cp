#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int n;
long long x, y;
long long l[100005], r[100005];
vector<pair<long long, int> > stop;
stack<int> s;

int main() {
    scanf("%d%lld%lld", &n, &x, &y);
    for (int i=0; i<n; i++) {
        scanf("%lld%lld", &l[i], &r[i]);
        stop.push_back({l[i], -i-1});
        stop.push_back({r[i], i+1});
    }

    sort(stop.begin(), stop.end());

    long long ans = 0LL;
    for (pair<long long, int> ss: stop) {
        if (ss.second < 0) { // is start
            if (!s.empty()) {
                int peek = s.top();
                if (y * (ss.first - r[peek]) < x) {
                    ans += y * (ss.first - r[peek]);
                    ans %= MOD;
                    s.pop();
                    // printf("acara ke %d pake yg habis acara %d\n", abs(ss.second)-1, peek);
                } else {
                    ans += x;
                    ans %= MOD;
                    // printf("acara ke %d beli baru\n", abs(ss.second)-1);
                }
            } else {
                ans += x;
                ans %= MOD;
                // printf("acara ke %d beli baru\n", abs(ss.second)-1);
            }
            ans += y * (r[abs(ss.second)-1] - l[abs(ss.second)-1]);
            ans %= MOD;
        } else { // is end
            // printf("push %d\n", ss.second);
            s.push(abs(ss.second)-1);
        }
    }
    printf("%lld\n", ans);
}