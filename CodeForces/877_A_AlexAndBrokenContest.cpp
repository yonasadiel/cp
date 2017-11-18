#include <iostream>
using namespace std;

int main() {
  string s;
  cin >> s;
  int cnt = 0;
  string key[] = {"Danil", "Olya", "Slava", "Ann", "Nikita"};
  for (int i=0; i<5; i++) {
    while (s.find(key[i]) != string::npos) { cnt++; s.replace(s.find(key[i]), key[i].length(), "x"); }
  }
  if (cnt == 1) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}