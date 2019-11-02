//ac
#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int, int>
using namespace std;

int n;
int a[200] = {0};
int b[200] = {0};

int ask() {
    int x;

    cout << "Q";
    for (int i=0; i<n; i++) cout << " " << a[i];
    cout << endl;
    cin >> x;
    return x;
}

int main() {
    cin >> n;

    int x = ask();
    for (int i=0; i<n; i++) {
        a[i] = 1;
        int d = ask();
        if (d > x) b[i] = 1;
        a[i] = 0;
    }

    cout << "A";
    for (int i=0; i<n; i++)  cout << " " << b[i];
    cout << endl;
}