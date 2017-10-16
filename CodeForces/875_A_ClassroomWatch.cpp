#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n;

int check(int x) {
  int sum = x;
  while (x > 0) {
    sum += (x%10);
    x /= 10;
  }
  return sum;
}

vector<int> v;

int main() {
  scanf("%d",&n);
  int cnt = 0;
  for (int k=n; k>n-1000 && k >= 0; k--) {
    if (check(k) == n) {
      cnt++;
      v.push_back(k);
    }
  }
  sort(v.begin(), v.end());
  printf("%d\n", cnt);
  for (int i=0; i<v.size(); i++) {
    printf("%d\n", v[i]);
  }
}