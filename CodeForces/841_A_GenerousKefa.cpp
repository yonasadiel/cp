#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int main() {
  int n,k;
  int cnt[100];
  bool bisa = true;
  string s;
  memset(cnt,0, sizeof cnt);

  scanf("%d%d",&n,&k);
  cin >> s;
  for (int i=0; i<n; i++) {
    cnt[s[i] - 'a']++;
    if (cnt[s[i] - 'a'] > k) {
      bisa = false;
    }
  }

  if (bisa) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }
}