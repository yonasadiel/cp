#include <cstdio>
using namespace std;

int n;
char str[100005];

int main() {
  scanf("%d\n",&n);
  scanf("%s",str);

  int pos = 0;
  int cx = 0;
  int cy = 0;
  int p = 0;
  for (int i=0; i<n; i++) {
    if (str[i] == 'U') { cy++; }
    if (str[i] == 'R') { cx++; }
    if (cx > cy) {
      if (pos == 1) p++;
      pos = -1;
    }
    if (cx < cy) {
      if (pos == -1) p++;
      pos = 1;
    }
  }
  printf("%d\n", p);
}