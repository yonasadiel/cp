#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int arr[100005]; int an;
int brr[100005]; int bn;
int crr[100005];

void exec(int tc) {
    scanf("%d", &n);
    an = bn = 0;
    for (int i=0; i<n; i++) {
        scanf("%d", &crr[i]);
        if (i&1) arr[an++] = crr[i];
        else brr[bn++] = crr[i];
    }
    sort(arr, arr + an);
    sort(brr, brr + bn);
    sort(crr, crr + n);

    int first;
    for (first=0; first<n; first++) {
        if (first&1) {
            if (arr[first/2] != crr[first]) break;
        } else {
            if (brr[first/2] != crr[first]) break;
        }
    }

    if (first == n) {
        printf("Case #%d: OK\n", tc);
    } else {
        printf("Case #%d: %d\n", tc, first);
    }
}

int main() {
    int t;
    scanf("%d",&t);
    for (int i=1; i<=t; i++) {
        exec(i);
    }
}