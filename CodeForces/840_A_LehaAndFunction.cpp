#include <cstdio>
#include <algorithm>
#include <utility>
#include <iostream>
#include <vector>
#define MAXN 200005
using namespace std;

int m,a;
pair<int, int> brr[MAXN];
int arr[MAXN], crr[MAXN];

bool desc(int a, int b) { return (a > b); }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> m;
  for (int i=0; i<m; i++) { cin >> arr[i]; }
  for (int i=0; i<m; i++) { cin >> brr[i].first; brr[i].second = i; }
  sort(arr, arr + m, desc);
  sort(brr, brr + m);
  for (int i=0; i<m; i++) { crr[brr[i].second] = arr[i]; }
  for (int i=0; i<m; i++) { cout << crr[i]; if (i == m-1) cout << '\n'; else cout << ' '; }

}