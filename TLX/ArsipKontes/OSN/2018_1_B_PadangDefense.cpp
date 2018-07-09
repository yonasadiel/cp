#include <bits/stdc++.h>
#define MAXAB 2005
#define co pair<int, int>
#define mp make_pair
#define ge first
#define ga second
using namespace std;

co pre[MAXAB][MAXAB];
char s[MAXAB][MAXAB];
int len[MAXAB][MAXAB];
char subsoal[10];
int ge, ga, q;
int l, r;

void precompute() {
  co st = mp(1, 1);
  s[1][1] = '1';
  len[1][1] = 0;

  queue<co> q;
  q.push(st);
  while (!q.empty()) {
    co cur = q.front(); q.pop();
    if (cur.ge + cur.ga < MAXAB) {
      pre[cur.ge + cur.ga][cur.ga] = cur;
      pre[cur.ge][cur.ga + cur.ge] = cur;
      s[cur.ge + cur.ga][cur.ga] = '0';
      s[cur.ge][cur.ga + cur.ge] = '1';
      len[cur.ge + cur.ga][cur.ga] = len[cur.ge][cur.ga] + 1;
      len[cur.ge][cur.ga + cur.ge] = len[cur.ge][cur.ga] + 1;
      q.push(mp(cur.ge + cur.ga, cur.ga));
      q.push(mp(cur.ge, cur.ga + cur.ge));
    }
  }
}

int main() {
  memset(len, -1, sizeof len);
  precompute();

  scanf("%s", subsoal);
  scanf("%d%d%d", &ga, &ge, &q);
  ge++;
  if (len[ge][ga] == -1) {
    printf("TIDAK MUNGKIN\n");
    while (q--) scanf("%d%d", &l, &r);
  } else {
    printf("MUNGKIN\n");
    while (q--) {
      scanf("%d%d", &l, &r);
      if (r > len[ge][ga]) {
        printf("DI LUAR BATAS\n");
      } else {
        int i = len[ge][ga];
        co cur = mp(ge, ga);
        string ans = "";
        while (i >= l) {
          if (i <= r) {
            ans = s[cur.ge][cur.ga] + ans;
          }
          cur = pre[cur.ge][cur.ga];
          i--;
        }
        cout << ans << "\n";
      }
    }
  }
}