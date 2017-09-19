#include <cstdio>
#include <cstring>
using namespace std;

int n;
int l[105];
int r[105];
bool belum[105];
int head = 0;

int caribaru() {
  for (int i=1; i<=n; i++) {
    if (l[i] == 0 && belum[i] && i != head) {
      return i;
    }
  }
  //
}

int main() {
  memset(belum, true, sizeof belum);
  scanf("%d",&n);
  for (int i=1; i<=n; i++) {
    scanf("%d%d",&l[i],&r[i]);
  }

  for (int i=1; i<=n && head == 0; i++) {
    if (l[i] == 0) head = i;
  }

  int state = head;

  while (state != 0) {
    belum[state] = false;

    if (r[state] == 0) {
      int ne = caribaru();
      r[state] = ne;
      l[ne] = state;
    }

    state = r[state];
  }

  for (int i=1; i<=n; i++) {
    printf("%d %d\n",l[i], r[i]);
  }
}