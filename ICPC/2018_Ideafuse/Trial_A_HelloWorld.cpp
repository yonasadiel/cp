#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> v;
  long long m;
  m = 2000000000; // tle
  m = 1000000000; // ac
  for (long long i=0; i<m; i++) {
    if (i % 1000 == 0) v.clear();
    v.push_back(i);
  }

  vector<string> v;
  vector<string> b;
  b.push_back("abc");
  b.push_back("def");
  b.push_back("ghi");
  for (auto a : b) {
    v.push_back(a);
  }
  
  printf("Hello world!\n");
}