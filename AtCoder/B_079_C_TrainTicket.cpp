#include <cstdio>
using namespace std;

int main() {
  int n;
  scanf("%d",&n);

  int a = (n/1000)%10;
  int b = (n/100)%10;
  int c = (n/10)%10;
  int d = (n/1)%10;

       if (a+b+c+d == 7) { printf("%d+%d+%d+%d=7\n",a,b,c,d); }
  else if (a+b+c-d == 7) { printf("%d+%d+%d-%d=7\n",a,b,c,d); }
  else if (a+b-c+d == 7) { printf("%d+%d-%d+%d=7\n",a,b,c,d); }
  else if (a+b-c-d == 7) { printf("%d+%d-%d-%d=7\n",a,b,c,d); }
  else if (a-b+c+d == 7) { printf("%d-%d+%d+%d=7\n",a,b,c,d); }
  else if (a-b+c-d == 7) { printf("%d-%d+%d-%d=7\n",a,b,c,d); }
  else if (a-b-c+d == 7) { printf("%d-%d-%d+%d=7\n",a,b,c,d); }
  else if (a-b+c-d == 7) { printf("%d-%d-%d-%d=7\n",a,b,c,d); }
}