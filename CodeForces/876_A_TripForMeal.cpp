#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
  int n,a,b,c;
  scanf("%d%d%d%d",&n,&a,&b,&c);

  int sum = 0;
  n--;
  if (c < a && c < b) {
    if (a < b) {
      if (n > 0) {
        sum += a;
        n--;
      }
      sum += n * c;
    } else {
      if (n > 0) {
        sum += b;
        n--;
      }
      sum += n * c;
    }
  } else {
    sum += n * min(a,b);
  }

  printf("%d\n",sum);

}