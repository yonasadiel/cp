#include <cstdio>
#include <cstring>
using namespace std;

int n;
char s[1005], s2[1005];

int main() {
  scanf("%d",&n);
  for (int i=0; i<n; i++) {
    memset(s2,0,sizeof(s2));
    scanf("%s",s);
    for (int j=0; j<strlen(s); j++) {
      s2[j] = s[strlen(s)-j-1];
    }
    if (!strcmp(s,s2)) {
      printf("palindrom\n");
    } else {
      printf("bukan palindrom\n");
    }
  }
}