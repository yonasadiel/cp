#include <cstdio>
using namespace std;

int wattToBill(int watt) {
  int ans = 0;
  if (watt > 100) { ans += 2 * 100; watt -= 100; } else { return ans + watt * 2; }
  if (watt > 9900) { ans += 3 * 9900; watt -= 9900; } else { return ans + watt * 3; }
  if (watt > 990000) { ans += 5 * 990000; watt -= 990000; } else { return ans + watt * 5; }
  ans += watt * 7;
  return ans;
}

int billToWatt(int bill) {
  int ans = 0;
  if (bill > 200) { ans += 200 / 2; bill -= 200; } else { return (bill%2)? -1 : (ans + bill / 2); }
  if (bill > 29700) { ans += 29700 / 3; bill -= 29700; } else { return (bill%3)? -1 : (ans + bill / 3); }
  if (bill > 4950000) { ans += 4950000 / 5; bill -= 4950000; } else { return (bill%5)? -1 : (ans + bill / 5); }
  ans += bill / 7;
  return (bill%7)? -1 : ans;
}

int a,b;
int aa;
bool bisa(int x) {
  return wattToBill(aa-x) - wattToBill(x) >= b;
}

int main() {
  scanf("%d%d", &a,&b);
  while (a > 0 || b > 0) {
    aa = billToWatt(a);
    int hi = aa/2+1;
    int lo = 0;
    while (lo < hi) {
      int mi = (hi + lo)/2;
      if (bisa(mi) && !bisa(mi+1)) {
        hi = mi;
        lo = mi;
      } else if (bisa(mi)) {
        lo = mi+1;
      } else {
        hi = mi-1;
      }
    }
    printf("%d\n",wattToBill(hi));
    scanf("%d %d", &a, &b);
  }
}