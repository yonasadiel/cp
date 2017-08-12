#include <cstdio>
using namespace std;

int t;
long long a,b,c,d;

int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
    printf("%lld\n",d-a+c-b);
  }
}