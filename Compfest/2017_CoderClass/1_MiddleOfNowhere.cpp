#include <cstdio>
using namespace std;

int main() {
  int t;
  double n,m;
  scanf("%d",&t);
  while (t--) {
    scanf("%lf%lf",&n,&m);
    printf("%.7lf\n",m*m/n);
  }
}