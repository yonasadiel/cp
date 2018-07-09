#include <bits/stdc++.h>
#define ll long long
using namespace std;

char subsoal[10];
char s[100005];
ll s_len;
ll k, q;
ll n;
ll l, r;
ll l_dec, l_dec_step[100005];
ll r_dec, r_dec_step[100005];
ll highest_col;

void find_highest_col() {
  highest_col = l_dec * k + 1;
}

bool in_bound(ll left, ll test, ll right) {
  return left <= test && test <= right;
}

ll find_y(ll col) {
  ll l_bound = 1, r_bound = n;
  ll ans = 1;
  ll lo, mi, hi;

  lo = 0, hi = k-1;
  while (lo <= hi) {
    mi = (lo + hi) / 2;
    ll l_next_dec = (ll) l_dec * (mi + 1), l_curr_dec = (ll) l_dec * mi;
    ll r_next_dec = (ll) r_dec * (mi + 1), r_curr_dec = (ll) r_dec * mi;
    if (!in_bound(l_bound + l_next_dec, col, r_bound - r_next_dec) &&
         in_bound(l_bound + l_curr_dec, col, r_bound - r_curr_dec)) {
      break;
    } else if (in_bound(l_bound + l_curr_dec, col, r_bound - r_curr_dec)) {
      lo = mi + 1;
    } else {
      hi = mi - 1;
    }
  }
  l_bound += (ll) l_dec * mi;
  r_bound -= (ll) r_dec * mi;
  ans += (ll) s_len * mi;

  lo = 0, hi = s_len;
  while (lo <= hi) {
    mi = (lo + hi) / 2;
    if (mi == s_len || (
        !in_bound(l_bound + l_dec_step[mi+1], col, r_bound - r_dec_step[mi+1]) &&
         in_bound(l_bound + l_dec_step[mi]  , col, r_bound - r_dec_step[mi]  ))) {
      break;
    } else if (in_bound(l_bound + l_dec_step[mi], col, r_bound - r_dec_step[mi])) {
      lo = mi + 1;
    } else {
      hi = mi - 1;
    }
  }
  ans += (ll) mi;
  return ans;
}

int main() {
  scanf("%s\n", subsoal);
  scanf("%s\n", s);
  scanf("%lld%lld", &k, &q);

  l_dec = r_dec = 0;
  s_len = strlen(s);
  n = (ll) s_len * k + 1;
  l_dec_step[0] = r_dec_step[0] = 0;
  for (ll i = 0; i < s_len; i++) {
    l_dec_step[i+1] = l_dec_step[i]; r_dec_step[i+1] = r_dec_step[i];
    if (s[i] == 'B') l_dec_step[i+1]++; else if (s[i] == 'A') r_dec_step[i+1]++; else return -2;
    if (s[i] == 'B') l_dec++;           else if (s[i] == 'A') r_dec++;           else return -2;
  }
  find_highest_col();

  while (q--) {
    scanf("%lld%lld", &l, &r);

    ll ans;
    if (l <= highest_col && highest_col <= r) {
      ans = n;
    } else if (l > highest_col) {
      ans = find_y(l);
    } else {
      ans = find_y(r);
    }
    if (ans < 0 || ans > n) return -1;
    printf("%lld\n", ans);
  }
}