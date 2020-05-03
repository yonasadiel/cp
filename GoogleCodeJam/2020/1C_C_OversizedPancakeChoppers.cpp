#include <bits/stdc++.h>
#define ll long long
#define fraction pair<ll, ll>
using namespace std;

ll a[10005];

void solve(int tc) {
  ll n, d;

  scanf("%lld %lld", &n, &d);
  for (ll i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
  }
  sort(a, a + n);
  ll ans = d - 1;

  vector<fraction> poss_ans;
  fraction max_poss_slice;
  for (ll mult = 1; mult <= d; mult++) {
    for (ll i = 0; i < n; i++) {
      ll dividen = a[i] / __gcd(a[i], mult);
      ll divisor = mult / __gcd(a[i], mult);
      poss_ans.push_back(make_pair(dividen, divisor));
    }
  }
  sort(poss_ans.begin(), poss_ans.end(), [](fraction a, fraction b) {
    return a.first * b.second < b.first * a.second;
  });
  int lo = 0, hi = poss_ans.size();
  while (lo < hi) {
    int mi = (lo + hi) / 2;
    fraction slice_size = poss_ans[mi];
    ll count = 0;
    for (int i = 0; i < n; i++) {
      count += a[i] * slice_size.second / slice_size.first;
    }
    if (count >= d) {
      max_poss_slice = slice_size;
      lo = mi + 1;
    } else {
      hi = mi;
    }
  }


  map<fraction, fraction> m; // a/b as slice => (n of slice, cost)
  for (ll mult = 1; mult <= d; mult++) {
    for (ll i = 0; i < n; i++) {
      ll dividen = a[i] / __gcd(a[i], mult);
      ll divisor = mult / __gcd(a[i], mult);
      fraction key = make_pair(dividen, divisor);
      if (m.find(key) != m.end()) {
        fraction l = m[key];
        if (l.first + mult > d) {
          m[key].first = d;
          m[key].second += (d - l.first);
        } else {
          m[key].first += mult;
          m[key].second += mult - 1;
        }
      } else {
        m[key] = make_pair(mult, mult - 1);
      }
    }
  }
  for (ll i = 0; i < n; i++) {
    for (ll mult = 1; mult <= d; mult++) {
      ll dividen = a[i] / __gcd(a[i], mult);
      ll divisor = mult / __gcd(a[i], mult);
      fraction key = make_pair(dividen, divisor);
      // printf("%lld/%lld = %lld slice, cost %lld\n", key.first, key.second, m[key].first, m[key].second);
      if (dividen * max_poss_slice.second > max_poss_slice.first * divisor) {
        continue;
      }
      if (m[key].first < d) {
        ans = min(ans, m[key].second + d - m[key].first);
      } else {
        ans = min(ans, m[key].second);
      }
    }
  }
  printf("Case #%d: %lld\n", tc, ans);
}

int main() {
  int t;
  scanf("%d", &t);
  for (int i = 1; i <= t; i++) solve(i);
}

