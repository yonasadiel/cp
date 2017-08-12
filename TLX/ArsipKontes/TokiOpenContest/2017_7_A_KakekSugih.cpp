#include <cstdio>
using namespace std;

int main() {
  int n;
  scanf("%d",&n);
  if (n == 0) printf("%d\n",1);
  if (n == 1) printf("%d\n",1);
  if (n == 2) printf("%d\n",1 + 2);
  if (n == 3) printf("%d\n",1 + 6);
  if (n == 4) printf("%d\n",1 + 12 + 6);
  if (n == 5) printf("%d\n",1 + 20 + 30);
  if (n == 6) printf("%d\n",1 + 30 + 90 + 20);
  if (n == 7) printf("%d\n",1 + 42 + 210 + 140);
  if (n == 8) printf("%d\n",1 + 56 + 420 + 560 + 70);
  if (n == 9) printf("%d\n",1 + 72 + 756 + 1680 + 630);
  if (n == 10) printf("%d\n",1 + 90 + 1260 + 4200 + 3150 + 252);
}