#include <cstdio>
using namespace std;

int n;
long long a,b;

bool valid (long long cek, long long kubik) {
  return (cek <= 1000000) && (cek * cek * cek <= kubik);
}

long long akartiga(long long kubik) {
  long long lo = 0, hi = 100000000, ans;
  while (lo <= hi) {
    long long mi = (lo+hi)/2;
    if (valid(mi, kubik) && !valid(mi+1, kubik)) {
      ans = mi;
      break;
    } else if (valid(mi, kubik)) {
      lo = mi+1;
    } else {
      hi = mi-1;
    }
  }
  return ans;
}

bool iskubik(long long _akartiga, long long kubik) {
  return (_akartiga <= 1000000) && (_akartiga*_akartiga*_akartiga == kubik);
}

int main() {
  scanf("%d",&n);
  while (n--) {
    bool ret = true;
    scanf("%I64d%I64d",&a,&b);

    long long _akartiga = akartiga(a*b);

    if (iskubik(_akartiga, a*b) && (a%_akartiga == 0) && (b%_akartiga == 0)) {
      printf("Yes\n");
    } else {
      printf("No\n");
    }
  }

}