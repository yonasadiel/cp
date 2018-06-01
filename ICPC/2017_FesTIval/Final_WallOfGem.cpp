#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;

char pet[305][305];

void maincase(int kasus) {
    int n,m;
    scanf("%d%d\n",&n,&m);
    int cnt1 = 0;
    int cnt2 = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            scanf("%c",&pet[i][j]);
            if ((i+j)%2 == 0) {
                if (pet[i][j] == '/') { cnt1++; }
                else { cnt2++; }
            } else {
                if (pet[i][j] == '/') { cnt2++; }
                else { cnt1++; }
            }
        }
        scanf("\n");
    }

    printf("Case #%d: %d\n", kasus, min(cnt1, cnt2));

}

int main(){
    int cases;
    scanf("%d",&cases);
    for (int i=1; i<=cases; i++) {
        maincase(i);
    }
}
