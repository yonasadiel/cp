#include <vector>
#include <stack>
#include <queue>
#include <cstdio>
#include <algorithm>
using namespace std;

void solve() {
    int n;
    int* arr;
    scanf("%d", &n);
    arr = new int[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr + n);
    bool first = true;
    for (int i = 0; i < n; i++) {
        if (i == 0 || arr[i] != arr[i-1]) {
            if (!first) {
                printf(" ");
            }
            first = false;
            printf("%d", arr[i]);
        }
    }
    for (int i = 0; i < n; i++) {
        if (i > 0 && arr[i] == arr[i-1]) {
            if (!first) {
                printf(" ");
            }
            first = false;
            printf("%d", arr[i]);
        }
    }
    printf("\n");
    delete arr;
}

int main() {
    int tc;
    scanf("%d", &tc);
    for (int i = 0; i < tc; i++) {
        solve();
    }
}