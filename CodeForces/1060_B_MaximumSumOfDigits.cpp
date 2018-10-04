#include <bits/stdc++.h>
using namespace std;

int s(long long l) {
    long long sum = 0;
    while (l > 0) {
        sum += l%10;
        l/=10;
    }
    return sum;
}

int f(long long l, long long k) {
    return s(l - k) + s(k);
}

long long jawab(long long n) {
    long long a = n, k = 1;
    while (a > 10) {
        a /= 10;
        k *= 10;
    }
    return a * k - 1;
}

int main() {
    long long n;

    cin >> n;
    int guess = f(n, jawab(n));
    cout << guess << endl;
}