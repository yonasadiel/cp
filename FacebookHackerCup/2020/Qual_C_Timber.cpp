#include <bits/stdc++.h>
using namespace std;

struct tree {
  int lp, rp, idx;
  tree() {}
  tree(int _lp, int _rp, int _idx): lp(_lp), rp(_rp), idx(_idx) { }
};

void solve(int tc) {
  int n;
  scanf("%d", &n);
  vector<tree> fall_le, fall_ri;
  for (int i = 0; i < n; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    fall_le.push_back(tree(a - b, a, i));
    fall_ri.push_back(tree(a, a + b, i));
  }
  sort(fall_le.begin(), fall_le.end(), [](const tree& a, const tree& b) {
    return a.lp > b.lp;
  });
  sort(fall_ri.begin(), fall_ri.end(), [](const tree& a, const tree& b) {
    return a.rp < b.rp;
  });
  map<int, int> dp_le, dp_ri;
  for (const tree& t : fall_le) {
    int curr_max = (dp_le.find(t.lp) == dp_le.end()) ? 0 : dp_le[t.lp];
    if (dp_le.find(t.rp) != dp_le.end()) {
      curr_max = max(curr_max, t.rp - t.lp + dp_le[t.rp]);
    } else {
      curr_max = max(curr_max, t.rp - t.lp);
    }
    dp_le[t.lp] = curr_max;
  }
  for (const tree& t : fall_ri) {
    int curr_max = (dp_ri.find(t.rp) == dp_ri.end()) ? 0 : dp_ri[t.rp];
    if (dp_ri.find(t.lp) != dp_ri.end()) {
      curr_max = max(curr_max, t.rp - t.lp + dp_ri[t.lp]);
    } else {
      curr_max = max(curr_max, t.rp - t.lp);
    }
    dp_ri[t.rp] = curr_max;
  }
  int ans = 0;
  for (const tree& t : fall_le) {
    ans = max(ans, dp_le[t.lp] + dp_ri[t.lp]);
  }
  for (const tree& t : fall_ri) {
    ans = max(ans, dp_le[t.rp] + dp_ri[t.rp]);
  }
  printf("Case #%d: %d\n", tc, ans);
}

int main() {
  int t;
  scanf("%d", &t);
  for (int i = 1; i <= t; i++) {
    solve(i);
  }
}
