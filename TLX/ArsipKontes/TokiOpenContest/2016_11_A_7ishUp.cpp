#include<bits/stdc++.h>
using namespace std;

int n;

int translate(string a) {
  if (a[0] == 'A') return 1;
  if (a[0] == '2') return 2;
  if (a[0] == '3') return 3;
  if (a[0] == '4') return 4;
  if (a[0] == '5') return 5;
  if (a[0] == '6') return 6;
  if (a[0] == '7') return 7;
  if (a[0] == '8') return 8;
  if (a[0] == '9') return 9;
  if (a[0] == '1') return 10;
  if (a[0] == 'J') return 11;
  if (a[0] == 'Q') return 12;
  if (a[0] == 'K') return 13;
}

string back[14] = {"0","A","2","3","4","5","6","7","8","9","10","J","Q","K"};

int main() {
  scanf("%d",&n);
  string sinp;
  while (n--) {
    cin>>sinp;
    int i = translate(sinp);
    char elem = sinp[sinp.length()-1];
    bool first = true;
    for (int j = i+1; j<=13; j++) {
      if (!first) {
        cout<<" ";
      }
      cout<<back[j]<<elem;
      first = false;
    }
    for (int j = i-1; j>=1; j--) {
      if (!first) {
        cout<<" ";
      }
      cout<<back[j]<<elem;
      first = false;
    }
    cout<<endl;
  }
}
