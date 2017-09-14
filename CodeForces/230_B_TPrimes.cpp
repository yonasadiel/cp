#include <cstdio>
#include <cstring>
#include <cmath>
#define MAXN 1000005
using namespace std;

bool prima[MAXN];

void shieve() {
  memset(prima, true, sizeof prima);
  prima[0] = false;
  prima[1] = false;
  for (int i=2; i<MAXN; i++) {
    if (prima[i]) {
      for (int j=i*2; j<MAXN; j+=i) {
        prima[j] = false;
      }
    }
  }
}

int main() {
  shieve();
  int n;
  scanf("%d",&n);
  while (n--) {
    long long g;
    scanf("%I64d",&g);
    long long akar = sqrt(g);
    if (akar*akar == g && prima[akar]) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
}