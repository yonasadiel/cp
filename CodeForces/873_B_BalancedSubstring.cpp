#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100000
using namespace std;

int n;
char pet[MAXN+5];
int bal[MAXN+5];
int arrMinBal[2*MAXN+10];

int main() {
  memset(arrMinBal, -1, sizeof arrMinBal);
  bal[0] = 0;
  arrMinBal[0 + MAXN] = 0;
  int ans = 0;

  scanf("%d\n",&n);
  for (int i=0; i<n; i++) {
    scanf("%c",&pet[i]);
    if (pet[i] == '1') { bal[i+1] = bal[i] + 1; }
    else               { bal[i+1] = bal[i] - 1; }

    if (arrMinBal[bal[i+1] + MAXN] != -1) {
      ans = max(ans, i+1 - arrMinBal[bal[i+1] + MAXN]);
    } else {
      arrMinBal[bal[i+1] + MAXN] = i+1;
    }
  }

  printf("%d\n", ans);
}