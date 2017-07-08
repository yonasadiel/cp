#include<bits/stdc++.h>
using namespace std;

int n,m;
int arr[2005];
int arrm[2005];

int main() {
  scanf("%d%d",&n,&m);

  int minim = n / m;
  int j = 1;
  int cntChange = 0;
  int stockChange = n % m; //jumlah yang boleh sebanyak minim+1

  for (int i = 0; i < n; i++) {
    scanf("%d",&arr[i]);
    if (arr[i] <= m) {
      if (arrm[arr[i]] < minim) {
        arrm[arr[i]]++;
      } /*else if (arrm[arr[i]] == minim && stockChange > 0)  {
        stockChange--;
        arrm[arr[i]]++;
      } */else {
        arr[i] *= -1;
      }
    } else {
      arr[i] *= -1;
    }
  }

  for (int j = 1, i = 0; i < n, j <= m;) {
    if (arr[i] < 0) {
      if (arrm[j] < minim) {
        arrm[j]++;
        arr[i] = j;
        i++;
        cntChange++;
      } /*else if (arrm[j] == minim && stockChange > 0) {
        arrm[j]++;
        arr[i] = j;
        stockChange--;
        i++;
      } */else {
        j++;
      }
    } else {
      i++;
    }
  }

  printf("%d %d\n%d",minim,cntChange,arr[0]);
  for (int i = 1; i < n; i++) {
    printf(" %d",arr[i]>0 ? arr[i] : arr[i]*-1);
  }

}
