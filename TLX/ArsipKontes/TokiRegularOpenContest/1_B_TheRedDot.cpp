#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define mp make_pair
using namespace std;

int main() {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int n = (a+b+c)/7;
    if (n*4 == a || n*4 == b || n*4 == c) printf("YA\n");
    else printf("TIDAK\n");
}