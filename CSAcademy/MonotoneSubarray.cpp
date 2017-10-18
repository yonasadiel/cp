#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int a[200005];

int main() {
  scanf("%d",&n);
  for (int i=0; i<n; i++) {
    scanf("%d",&a[i]);
  }

  int streak_inc = 1;
  int streak_dec = 1;
  int streak = 0;
  for (int i=1; i<n; i++) {
    if (a[i] <= a[i-1]) {
      streak_dec++;
    } else {
      streak = max(streak, streak_dec);
      streak_dec = 1;
    }
    if (a[i] >= a[i-1]) {
      streak_inc++;
    } else {
      streak = max(streak, streak_inc);
      streak_inc = 1;
    }
  }

  streak = max(streak, streak_dec);
  streak = max(streak, streak_inc);
  printf("%d\n", streak);
}