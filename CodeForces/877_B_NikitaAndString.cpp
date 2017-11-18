#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

int n;
string s;
int dp[5005][5];

int ngedp(int pos, int state) {
  int &ret = dp[pos][state];
  
  if (ret == -1) {
    if (pos == n) {
      ret = 0;
    } else {
      if (state == 0) {
        ret = max(ngedp(pos+1, state), ngedp(pos, state+1));
      } else if (state == 1) {
        if (s[pos] == 'a') {
          ret = 1+max(ngedp(pos+1, state), ngedp(pos+1, state+1));
        } else {
          ret = max(ngedp(pos+1, state), ngedp(pos, state+1));
        }
      } else if (state == 2) {
        if (s[pos] == 'b') {
          ret = 1+max(ngedp(pos+1, state), ngedp(pos+1, state+1));
        } else {
          ret = max(ngedp(pos+1, state), ngedp(pos, state+1));
        }
      } else if (state == 3) {
        if (s[pos] == 'a') {
          ret = 1+ngedp(pos+1, state);
        } else {
          ret = ngedp(pos+1, state);
        }
      }
    }
  }
  return ret;
}

void bt(int pos, int state) {
  int ret = dp[pos][state];
  
  if (pos == n) {
    return;
  } else {
    if (state == 0) {
      if (ret == ngedp(pos+1, state)) {
        bt(pos+1, state);
      } else {
        bt(pos, state+1);
      }
    }
  }
}

int main() {
  memset(dp, -1, sizeof dp);

  cin >> s;
  n = s.length();
  printf("%d\n", ngedp(0, 0));
}