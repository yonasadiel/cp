#include <cstdio>
#include <cstring>
using namespace std;

int ans = 0;
char s[55];

int main() {
  scanf("%s",s);
  for (int i=0; i<strlen(s); i++) {
    if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
      ans++;
    } else if (s[i] == '1' || s[i] == '3' || s[i] == '5' || s[i] == '7' || s[i] == '9') {
      ans++;
    }
  }
  printf("%d\n", ans);
}