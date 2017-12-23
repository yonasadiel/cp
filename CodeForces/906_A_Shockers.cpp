#include <cstdio>
#include <iostream>
using namespace std;

int n;
int p[30];
char c[100005];
string str[100005];

int main() {
  scanf("%d",&n);
  for (int i=0; i<26; i++) { p[i] = 1; }

  for (int k=0; k<n; k++) {
    scanf("\n%c", &c[k]); cin >> str[k];
  }

  char kunci = str[n-1][0];
  int bisa = 0;
  int ans = 0;
  for (int k=0; k<n-1; k++) {
    if (c[k] == '.') {
      for (int i=0; i<str[k].length(); i++) { p[str[k][i]-'a'] = 0; }
    } else if (c[k] == '!') {
      int t[30];
      for (int i=0; i<26; i++) { t[i] = 0; }
      for (int i=0; i<str[k].length(); i++) { t[str[k][i]-'a'] = 1; }
      for (int i=0; i<26; i++) { p[i] &= t[i]; }
      if (bisa) ans++;
    } else {
      if (bisa) ans++;
      p[str[k][0]-'a'] = 0;
    }

    int cnt = 0;
    for (int i=0; i<26; i++) { if (p[i]) cnt++; }
    // printf("%d\n", cnt);
    if (cnt == 1) bisa = 1;
    if (cnt == 0) while (1);

  }
  printf("%d\n", ans);
}