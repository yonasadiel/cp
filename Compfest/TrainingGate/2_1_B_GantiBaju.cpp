#include <cstdio>
using namespace std;

int main() {
  double p;
  scanf("%lf", &p);

  if (p == 0) {
    printf("0\n");
    return 0;
  }

  p  = p / 100;
  double ganjil = 0;
  double genap = 0;

  for (int i=0; ganjil+genap < (double) 0.9999999; i++) {
    double sisa = 1 - ganjil - genap;
    if (i%2 == 0) {
      ganjil += sisa*p;
    } else {
      genap += sisa*p;
    }
  }


  printf("%.7lf\n",ganjil);
}