#include <cstdio>
#include <cstring>
using namespace std;

int arr[2005], brr[2005];
bool cek[2000005];

int main() {
  memset(cek, false, sizeof cek);
  int n;
  scanf("%d",&n);
  for (int i=0; i<n; i++) {
    scanf("%d",&arr[i]);
    cek[arr[i]] = true;
  }
  for (int i=0; i<n; i++) {
    scanf("%d",&brr[i]);
    cek[brr[i]] = true;
  }

  int cnt = 0;
  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      if ((arr[i] ^ brr[j]) <= 2000000 && cek[(arr[i] ^ brr[j])]) {
        cnt++;
      }
    }
  }

  if (cnt&1) {
    printf("Koyomi\n");
  } else {
    printf("Karen\n");
  }
}