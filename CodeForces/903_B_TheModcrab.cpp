#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int hv, he, av, ae, cv;
vector<string> v;

int main() {
  scanf("%d%d%d",&hv,&av,&cv);
  scanf("%d%d",&he,&ae);

  while (he > 0) {
    if (hv-ae <= 0 && he > av) {
      v.push_back("HEAL");
      hv += cv;
    } else {
      v.push_back("STRIKE");
      he -= av;
    }
    hv -= ae;
  }

  printf("%d\n", v.size());
  for (int i=0; i<v.size(); i++) {
    cout << v[i] << "\n";
  }

}