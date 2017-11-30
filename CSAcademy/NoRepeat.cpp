#include <iostream>
using namespace std;

int n;
string str;

int main() {
  cin >> n;
  cin >> str;
  char ret = ' ';
  for (int j=0; j<n; j++) {
    char cc = str[j];
    int cnt = 0;
    for (int i=0; i<n; i++) {
      if (str[i] == cc) {
        cnt++;
      }
    }
    if (cnt == 1 && ret == ' ') ret = cc;
  }
  if (ret != ' ') {
    printf("%c\n",ret);
  } else {
    printf("-1\n");
  }
}