#include <cstdio>
#include <stack>
using namespace std;

int n;
int arr[100005];

int main() {
  scanf("%d",&n);
  for (int i=0; i<n; i++) {
    scanf("%d",&arr[i]);
  }

  stack<int> s;
  int cnt = 0;
  for (int i=0; i<n; i++) {
    while (!s.empty() && arr[i] < s.top()) {
      cnt++;
      s.pop();
    }

    if (s.empty() || arr[i] > s.top()) {
      s.push(arr[i]);
    }

  }
  while (!s.empty()) {
    cnt++;
    s.pop();
  }

  printf("%d\n", cnt);
}