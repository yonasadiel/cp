#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll ans;
ll fact[20];
int leading;
int cnt[10];
int used[10];

void bt(int digit) {
  if (digit == 10) {
    ll bawah = 1;
    ll atas = 0;
    for (int i=0; i<10; i++) {
      if (cnt[i] > 0 && used[i] == 0 && leading != i) return;
    }
    for (int i=0; i<10; i++) {
      atas += used[i];
      bawah *= fact[used[i]];
      //cout << used[i] << " ";
    }
    atas = fact[atas];
    //cout << " = " << atas << " / " << bawah << " = " << atas/bawah << "\n";
    ans += atas/bawah;
  } else {
    for (int i=0; i<=cnt[digit]; i++) {
      used[digit] += i;
      bt(digit+1);
      used[digit] -= i;
    }
  }
}

int main() {
  string s;
  cin >> s;

  fact[0] = 1; fact[1] = 1;
  for (ll i=2; i<20; i++) fact[i] = i * fact[i-1];

  memset(cnt, 0, sizeof cnt);
  for (char x : s) cnt[x - '0']++;

  memset(used, 0, sizeof used);
  ll fans = 0;
  for (leading=1; leading<10; leading++) {
    if (cnt[leading] > 0) {
      ans = 0;
      cnt[leading]--;
      bt(0);
      //cout << leading << " " << ans << "\n";
      fans += ans;
      cnt[leading]++;
    }
  }
  cout << fans << "\n";
}