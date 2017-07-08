#include<bits/stdc++.h>
using namespace std;

int n;
int p[200];
string kal;

bool strcheck(string ch, int num) {
  string dum = "";
  bool ada = false;
  for (int i = 0; i < ch.length(); i++) {
    if (ch[i] == ' ') dum = "";
    if (ch[i] == 'a' || ch[i] == 'e' || ch[i] == 'i' || ch[i] == 'o' || ch[i] == 'u' || ch[i] == 'y') num--;
  }
  if (num == 0) return true;
  else return false;
}

int main() {
  scanf("%d",&n);

  for (int i = 0; i < n; i++) {
    scanf("%d",&p[i]);
  }

  char dum; scanf("%c",&dum);

  bool bisa = true;
  for (int i = 0; i < n; i++) {
    getline(cin,kal);
    if (!strcheck(kal,p[i])) {
      bisa = false;
      //if (n == 100) cout<<i<<endl<<kal<<endl;
    }
  }

  if (bisa) printf("YES\n");
  else printf("NO\n");

}
