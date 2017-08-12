#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
  int t;
  scanf("%d",&t);
  while (t--) {
    int n, cnt[50], max_i = 0;
    memset(cnt, 0, sizeof cnt);
    string s;

    scanf("%d",&n);
    cin >> s;
    for (int i=0; i<n; i++) {
      cnt[s[i] - 'a']++;
      if (cnt[s[i] - 'a'] > cnt[max_i]) { max_i = s[i] - 'a'; }
    }

    printf("%d\n", n - cnt[max_i]);

  }
}