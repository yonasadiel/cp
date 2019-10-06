#include <bits/stdc++.h>
using namespace std;

bool pos[600];

int main() {
    memset(pos, true, sizeof pos);
    int n, s;
    scanf("%d%d",&n,&s);
    int ans = n*(n+1)/2;

    if (abs(ans-s)%2==1 || s > ans || s < -ans+2) {
        printf("Impossible\n");
    } else {
        for (int i=n; i>=1; i--) {
            if (ans-2*i >= s) {
                pos[i] = false;
                ans -= 2*i;
            }
        }
        if (!pos[1]) {
            bool nemu = false;
            for (int i=3; i<=n; i++) {
                if (!pos[i-1] && pos[i]) {
                    pos[i] = false;
                    pos[i-1] = true;
                    nemu = true;
                    break;
                }
            }
            if (!nemu) {
                int j = 4;
                while (pos[j]) j++;
                pos[2] = false;
                pos[j] = true;
                pos[j-1] = false;
            }
        }
        printf("1");
        for (int i=2; i<=n; i++) {
            if (pos[i]) printf("+"); else printf("-");
            printf("%d", i);
        }
        printf("\n");
    }
}