#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
  int n;
  scanf("%d",&n);
  while (n--) {
    int trgx, trgy, trgz;
    int pxa, pxb, pya, pyb;
    int d;

    scanf("%d%d%d",&trgx,&trgy,&trgz);
    scanf("%d%d",&pxa,&pya);
    scanf("%d%d",&pxb,&pyb);
    scanf("%d",&d);

    if (trgz <= d &&
        trgx >= min(pxa, pxb) && trgx <= max(pxa,pxb) &&
        trgy >= min(pya, pyb) && trgy <= max(pya,pyb)) {
      printf("shoot\n");
    } else {
      printf("hold\n");
    }
  }
}