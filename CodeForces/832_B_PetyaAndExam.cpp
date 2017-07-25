#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

bool is_good[256];
string pattern, good, query;
int n, ind_wildcard;

bool matches(char c_q, char c_p) {
  if (c_p == '?') return is_good[c_q];
  else return (c_q == c_p);
}

int main() {

  cin >> good;
  memset(is_good, false, sizeof is_good);
  for (int i=0; i<good.length(); i++) {
    is_good[good[i]] = true;
  }

  cin >> pattern;
  ind_wildcard = -1;
  for (int i=0; i<pattern.length(); i++) {
    if (pattern[i] == '*') ind_wildcard = i;
  }

  scanf("%d",&n);
  while(n--) {
    cin >> query;

    bool tmp = true;
    if (ind_wildcard != -1) {
      if (pattern.length()-1 > query.length()) { tmp = false; }
      else {
        int offs = query.length() - pattern.length() + 1;
        for (int q_i = 0, p_i = 0; q_i < query.length() && p_i < pattern.length(); q_i++) {
          if (pattern[p_i] == '*' && offs == 0) { q_i--; p_i++; continue; }
          if (pattern[p_i] == '*' && offs > 0) { if (is_good[query[q_i]]) { tmp = false; }  offs--; }
          else if (!matches(query[q_i], pattern[p_i])) { tmp = false; }

          if (pattern[p_i] != '*' || offs == 0) { p_i++; }
        }
      }
    } else {
      if (pattern.length() != query.length()) { tmp = false; }
      else {
        for (int i=0; i<pattern.length(); i++) {
          if (!matches(query[i], pattern[i])) { tmp = false; }
        }  
      }
    }
    
    if (tmp) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
}