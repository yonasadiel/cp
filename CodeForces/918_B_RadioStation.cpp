#include <iostream>
#include <cstdio>
using namespace std;

int ip[10005][5];
int ipt[5];
string nama[10005];
string str;

int main() {
  int n,m;
  scanf("%d%d",&n,&m);
  for (int i=0; i<n; i++) {
    cin >> nama[i];
    scanf("%d.%d.%d.%d", &ip[i][0], &ip[i][1], &ip[i][2], &ip[i][3]);
  }

  for (int i=0; i<m; i++) {
    cin >> str; cout << str << " ";
    scanf("%d.%d.%d.%d;", &ipt[0], &ipt[1], &ipt[2], &ipt[3]);
    printf("%d.%d.%d.%d; #", ipt[0], ipt[1], ipt[2], ipt[3]);
    for (int j=0; j<n; j++) {
      if (ipt[0] == ip[j][0] &&
          ipt[1] == ip[j][1] &&
          ipt[2] == ip[j][2] &&
          ipt[3] == ip[j][3]) {
        cout << nama[j];
      }
    }
    printf("\n");
  }
}