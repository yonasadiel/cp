#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int g1, g2, p1, p2, a, b;
    scanf("%d%d%d%d",&g1,&p1,&g2,&p2);
    
    for (int i=0; i<=g1; i++) {
      if (p1 == i*100/g1) {
        a = i; break;
      }
    }
    for (int i=g2; i>=0; i--) {
      if (p2 == i*100/g2) {
        b = i; break;
      }
    }
    printf("%d\n",min(g2-g1, b-a));
}