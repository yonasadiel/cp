#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, q;
char s[1000010];
int presum[30][1000010];

int count_occ(char c, int l, int r) {
  int ans = presum[c-'a'][r];
  if (l > 0) ans -= presum[c-'a'][l-1];
  return ans;
}

bool case1(int l, int r) {
  int m = (r+l)/2;
  for (char cc = 'a'; cc <= 'z'; cc++) {
    if (count_occ(cc, l, m-1) != count_occ(cc, m+1, r)) {
      return false;
    }
  }
  return true;
}

bool case2(int l1, int r1, int l2, int r2) {
  bool foundDiff = false;
  for (char cc = 'a'; cc <= 'z'; cc++) {
    int cnt_half_1 = count_occ(cc, l1, r1);
    int cnt_half_2 = count_occ(cc, l2, r2);
    if (cnt_half_1 != cnt_half_2) {
      if (foundDiff) return false;
      if (abs(cnt_half_1 - cnt_half_2) > 1) return false;
      foundDiff = true;
    }
  }
  return true;
}

void solve(int tc) {
  scanf(" %s", s);
  n = strlen(s);
  scanf("%d", &q);

  for (int j = 0; j < 26; j++) presum[j][0] = ((s[0] == 'a' + j) ? 1 : 0);
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < 26; j++) presum[j][i] = presum[j][i-1];
    presum[s[i]-'a'][i] = presum[s[i]-'a'][i-1] + 1;
  }

  int answer = 0;
  for (int qi = 0; qi < q; qi++) {
    int l, r;
    scanf("%d%d", &l, &r);
    r--; l--;
    if ((r-l+1) % 2 == 0) continue;
    if (r == l) { answer++; continue; }

    int m = (r+l)/2;
    // three cases:
    // [l..m-1] [m+1..r]
    // [l..m-1] [m..r]
    // [l..m] [m+1..r]
    
    if (case1(l, r)) { // delete the middle
      // printf("case1 = %d-%d\n", l+1, r+1);
      answer++;
      continue;
    }

    if (case2(l, m, m+1, r)) { // delete from first half
      // printf("case2 = %d-%d\n", l+1, r+1);
      answer++;
      continue;
    }

    if (case2(l, m-1, m, r)) { // delete from second half
      // printf("case3 = %d-%d\n", l+1, r+1);
      answer++;
      continue;
    }
  }
  printf("Case #%d: %d\n", tc, answer);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) solve(i);
}
