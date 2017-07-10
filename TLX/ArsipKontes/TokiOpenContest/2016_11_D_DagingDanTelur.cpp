#include<bits/stdc++.h>
using namespace std;

const long long maxn = 1000005;

bool prim[maxn];
long long arr[100005];

void shieve() {
  memset(prim, true, sizeof prim);
  prim[0] = false; prim[1] = false;
  for (long long i=2; i<maxn; i++) {
    if (prim[i])
      for (long long j=i*i; j<maxn; j+=i) {
        prim[j] = false;
      }
  }
}

int main() {
  long long n,k,m=0;
  scanf("%lld%lld",&n,&k);
  shieve();

  long long now=k;
  long long tmp=1e8+7;
  for (long long i=0; i<n; i++) {
    scanf("%lld",&arr[i]);
    if (prim[arr[i]]) {
      tmp=min(tmp,arr[i]);
      i--;
      n--;
      m++;
    }
  }

  sort(arr,arr+n);

  for (long long i=0; i<n; i++) {
    if (now >= arr[i]) {
      now = now-arr[i];
    } else {
      if (m >= 1) {
        if (now >=  tmp) printf("%lld\n",i+1);
        else printf("%lld\n",i);
      } else {
        printf("%lld\n",i);
      }
      return 0;
    }
  }

  if (m != 0 && now >= tmp) {
    if (m == 1) printf("One Punch!\n");
    else if (m > 1) printf("%lld\n",n+1);
  } else if (m != 0){
    printf("%lld\n",n);
  } else {
    printf("One Punch!\n");
  }
}
