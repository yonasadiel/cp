#include <cstdio>
using namespace std;

int parent[30];
char s1[100005];
char s2;

int findParent(int x) {
  if (parent[x] == x) return x;
  else {
    int p = findParent(parent[x]);
    parent[x] = p;
    return p;
  }
}

int ans = 0;
char ans1[30], ans2[30];

int main() {
  int n;
  for (int i=0; i<30; i++) { parent[i] = i; }
  scanf("%d\n", &n);
  for (int i=0; i<n; i++) {
    scanf("%c", &s1[i]);
  }
  scanf("\n");
  for (int i=0; i<n; i++) {
    scanf("%c", &s2);
    int p1 = findParent(s1[i] - 'a');
    int p2 = findParent(s2 - 'a');
    if (p1 != p2) {
      parent[p1] = p2;
      ans1[ans] = s1[i]; ans2[ans] = s2;
      ans++;
    }
  }
  printf("%d\n", ans);
  for (int i=0; i<ans; i++) {
    printf("%c %c\n", ans1[i], ans2[i]);
  }
}