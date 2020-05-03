#include <bits/stdc++.h>
using namespace std;

void solve(int tc) {
  int u, q[10005], f[30];
  char s[10005][20];
  set<char> alph;
  vector<pair<int, char> > l;

  scanf("%d", &u);
  for (char j = 'A'; j <= 'Z'; j++) {
    f[j - 'A'] = 0;
  }
  for (int i = 0; i < 10000; i++) {
    scanf("%d %[^\n]", &q[i], &s[i]);
    f[s[i][0] - 'A']++;
    for (int j = 0; j < strlen(s[i]); j++) {
      alph.insert(s[i][j]);
    }
  }
  for (char j = 'A'; j <= 'Z'; j++) {
    int _f = f[j - 'A'];
    if (_f > 0) {
      l.push_back(make_pair(_f, j));
    }
  }
  sort(l.rbegin(), l.rend());

  printf("Case #%d: ", tc);
  for (char cc : alph) {
    bool found = false;
    for (int i = 0; i < l.size(); i++) {
      if (l[i].second == cc) found = true;
    }
    if (!found) printf("%c", cc);
  }
  for (int i = 0; i < l.size(); i++) {
    printf("%c", l[i].second);
  }
  printf("\n");
}

int main() {
  int t;
  scanf("%d", &t);
  for (int i = 1; i <= t; i++) solve(i);
}

