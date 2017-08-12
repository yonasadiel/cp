#include <iostream>
using namespace std;

string s;
int sl;
long long ret = 1;

int main() {
  getline(cin,s);
  sl = s.length();
  for (int i=0; i<sl; i++) {
    if (s[i] == 'e' && i+1<sl && s[i+1] == 'u') {
      ret *= 3;
    } else if (s[i] == 'e') {
      ret *= 2;
    }
    ret %= 1000000007;
  }
  cout<<ret<<'\n';
}