#include<iostream>
#include<vector>
#include<algorithm>
#define pii pair<long long, long long>
#define fi first
#define se second
#define MOD 1000000007
using namespace std;

int n, q;
pii t[500005], w[500005];

long long llsqr(long long a) {
  a %= MOD;
  return (a * a) % MOD;
}

long long lladd(long long a, long long b) {
  return ((a % MOD) + (b % MOD)) % MOD;
}

long long llmul(long long a, long long b) {
  return ((a % MOD) * (b % MOD)) % MOD;
}

long long llpow(long long a, long long b) {
  if (b == 0) return 1;
  if (b == 1) return a;
  long long c = llpow(a, b/2);
  c = llmul(c, c);
  if (b % 2 == 0) return c;
  return llmul(c, a);
}

void solve(int tc) {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) { scanf("%lld %lld", &t[i].fi, &t[i].se); }
  scanf("%d", &q);
  for (int i = 0; i < q; i++) { scanf("%lld %lld", &w[i].fi, &w[i].se); }

  long long ans = 0, last_x, inc_val, sum;
  int cnt, ti;

  // x low to high
  sort(t, t + n, [](const pii& a, const pii& b) { return a.fi < b.fi; });
  sort(w, w + q, [](const pii& a, const pii& b) { return a.fi < b.fi; });
  cnt = 0, ti = 0;
  last_x = -1, inc_val = 0, sum = 0;
  for (int i = 0; i < q; i++) {
    if (cnt > 0) {
      long long step = w[i].fi - w[i-1].fi;
      long long new_inc = lladd(inc_val, llmul(llmul(2, cnt), step));
      sum = lladd(sum, llmul(llpow(2, MOD-2), llmul(step, lladd(new_inc, lladd(inc_val, llmul(2, cnt))))));
      inc_val = new_inc;
      // printf("i=%d|w=%lld|inc=%lld|step=%lld|ans=%lld\n", i, w[i].fi, inc_val, step, ans);
    }
    while (ti < n && t[ti].fi <= w[i].fi) {
      inc_val = lladd(inc_val, lladd(llmul(2, w[i].fi - t[ti].fi), MOD - 1));
      sum = lladd(sum, llsqr(w[i].fi - t[ti].fi));
      ti++;
      cnt++;
      // printf("i=%d|ti=%d|t=%lld|w=%lld|inc=%lld|ans=%lld\n", i, ti, t[ti].fi, w[i].fi, inc_val, ans);
    }
    ans = lladd(ans, sum);
    last_x = w[i].fi;
    // printf("well_idx=%d|sum=%lld|ans=%lld\n", i, sum, ans);
  }

  // x high to low
  sort(t, t + n, [](const pii& a, const pii& b) { return a.fi > b.fi; });
  sort(w, w + q, [](const pii& a, const pii& b) { return a.fi > b.fi; });
  cnt = 0, ti = 0;
  last_x = -1, inc_val = 0, sum = 0;
  for (int i = 0; i < q; i++) {
    if (cnt > 0) {
      long long step = w[i-1].fi - w[i].fi;
      long long new_inc = lladd(inc_val, llmul(llmul(2, cnt), step));
      sum = lladd(sum, llmul(llpow(2, MOD-2), llmul(step, lladd(new_inc, lladd(inc_val, llmul(2, cnt))))));
      inc_val = new_inc;
      // printf("i=%d|w=%lld|inc=%lld|step=%lld|ans=%lld\n", i, w[i].fi, inc_val, step, ans);
    }
    while (ti < n && t[ti].fi >= w[i].fi) {
      inc_val = lladd(inc_val, lladd(llmul(2, t[ti].fi - w[i].fi), MOD - 1));
      sum = lladd(sum, llsqr(t[ti].fi - w[i].fi));
      ti++;
      cnt++;
      // printf("i=%d|ti=%d|t=%lld|w=%lld|inc=%lld|ans=%lld\n", i, ti, t[ti].fi, w[i].fi, inc_val, ans);
    }
    ans = lladd(ans, sum);
    last_x = w[i].fi;
    // printf("well_idx=%d|sum=%lld|ans=%lld\n", i, sum, ans);
  }

  // y low to high
  sort(t, t + n, [](const pii& a, const pii& b) { return a.se < b.se; });
  sort(w, w + q, [](const pii& a, const pii& b) { return a.se < b.se; });
  cnt = 0, ti = 0;
  last_x = -1, inc_val = 0, sum = 0;
  for (int i = 0; i < q; i++) {
    if (cnt > 0) {
      long long step = w[i].se - w[i-1].se;
      long long new_inc = lladd(inc_val, llmul(llmul(2, cnt), step));
      sum = lladd(sum, llmul(llpow(2, MOD-2), llmul(step, lladd(new_inc, lladd(inc_val, llmul(2, cnt))))));
      inc_val = new_inc;
      // printf("i=%d|w=%lld|inc=%lld|step=%lld|ans=%lld\n", i, w[i].se, inc_val, step, ans);
    }
    while (ti < n && t[ti].se <= w[i].se) {
      inc_val = lladd(inc_val, lladd(llmul(2, w[i].se - t[ti].se), MOD - 1));
      sum = lladd(sum, llsqr(w[i].se - t[ti].se));
      ti++;
      cnt++;
      // printf("i=%d|ti=%d|t=%lld|w=%lld|inc=%lld|ans=%lld\n", i, ti, t[ti].se, w[i].se, inc_val, ans);
    }
    ans = lladd(ans, sum);
    last_x = w[i].se;
    // printf("well_idx=%d|sum=%lld|ans=%lld\n", i, sum, ans);
  }

  // y high to low
  sort(t, t + n, [](const pii& a, const pii& b) { return a.se > b.se; });
  sort(w, w + q, [](const pii& a, const pii& b) { return a.se > b.se; });
  cnt = 0, ti = 0;
  last_x = -1, inc_val = 0, sum = 0;
  for (int i = 0; i < q; i++) {
    if (cnt > 0) {
      long long step = w[i-1].se - w[i].se;
      long long new_inc = lladd(inc_val, llmul(llmul(2, cnt), step));
      sum = lladd(sum, llmul(llpow(2, MOD-2), llmul(step, lladd(new_inc, lladd(inc_val, llmul(2, cnt))))));
      inc_val = new_inc;
      // printf("i=%d|w=%lld|inc=%lld|step=%lld|ans=%lld\n", i, w[i].se, inc_val, step, ans);
    }
    while (ti < n && t[ti].se >= w[i].se) {
      inc_val = lladd(inc_val, lladd(llmul(2, t[ti].se - w[i].se), MOD - 1));
      sum = lladd(sum, llsqr(t[ti].se - w[i].se));
      ti++;
      cnt++;
      // printf("i=%d|ti=%d|t=%lld|w=%lld|inc=%lld|ans=%lld\n", i, ti, t[ti].se, w[i].se, inc_val, ans);
    }
    ans = lladd(ans, sum);
    last_x = w[i].se;
    // printf("well_idx=%d|sum=%lld|ans=%lld\n", i, sum, ans);
  }
  

  printf("Case #%d: %lld\n", tc, ans);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) solve(i);
}
