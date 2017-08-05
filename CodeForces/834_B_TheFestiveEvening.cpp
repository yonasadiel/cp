#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

string s;

int main() {
  int door_first[255];
  int door_last[255];
  memset(door_first, -1, sizeof door_first);
  memset(door_last, -1, sizeof door_last);
  int n,k;
  bool ret = false;

  scanf("%d%d",&n,&k);
  cin >> s;
  for (int i=0; i<n; i++) {
    if (door_first[s[i]] == -1) door_first[s[i]] = i;
    door_last[s[i]] = i;
  }

  int cnt = 0;
  for (int i=0; i<n; i++) {
    if (door_first[s[i]] == i) cnt++;
    if (cnt > k) ret = true;
    if (door_last[s[i]] == i) cnt--;
  }

  if (ret) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }
  
}