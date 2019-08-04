#include <bits/stdc++.h>
#define HI 1000000
using namespace std;

// NOTE: THIS IS ONLY HELPER FILE

int r, c;
char m[3000];
char s[1005][1005];

int dp[1005][1005];

const int DIR = 2;
int dr[] = {0, 1};
int dc[] = {1, 0};

void floodfill(int rs, int cs) {
    s[rs][cs] = '$';
    for (int i = 0; i < DIR; i++) {
        int rn = rs + dr[i];
        int cn = cs + dc[i];
        if (rn < r && cn < c && s[rn][cn] == '.') {
            floodfill(rn, cn);
        }
    }
}

void calc() {
    for (int i=r-1; i>=0; i--) {
        for (int j=c-1; j>=0; j--) {
            if (i == r-1 && j == c-1) {
                dp[i][j] = 1;
            } else if (s[i][j] == '#') {
                dp[i][j] = 0;
            } else {
                dp[i][j] = 0;
                if (i < r-1) dp[i][j] += dp[i+1][j];
                if (j < c-1) dp[i][j] += dp[i][j+1];
                if (dp[i][j] > HI) dp[i][j] = HI;
            }
        }
    }
}

int main() {
    scanf("%d %d\n", &r, &c);
    scanf("%s\n", m);
    for (int i=0; i<r; i++) {
        scanf("%s\n", s[i]);
    }

    // floodfill(0, 0);
    // calc();
    // for (int i = 0; i < r; i++) {
    //     for (int j = 0; j < c; j++) {
    //         if (s[i][j] == '$' && dp[i][j] > 0) s[i][j] = '%';
    //     }
    // }

    int slope_min = 0, slope_max = 0;
    int rn = 0, cn = 0;
    s[rn][cn] = '@';
    for (int i = 0; i < strlen(m); i++) {
        if (m[i] == 'v') rn++; else cn++;
        s[rn][cn] = '@';
        slope_max = max(slope_max, rn-cn);
        slope_min = min(slope_min, rn-cn);
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            // area atas
            if (i > 246) { if (i + 1 <  r && s[i][j] == '.' && s[i+1][j] == '@') s[i][j] = 'x'; }
            else         { if (j - 1 >= 0 && s[i][j] == '.' && s[i][j-1] == '@') s[i][j] = 'x'; }

            // area bawah
            if (i > 639) { if (j + 1 <  r && s[i][j] == '.' && s[i][j+1] == '@') s[i][j] = 'x'; }
            else         { if (i - 1 >= 0 && s[i][j] == '.' && s[i-1][j] == '@') s[i][j] = 'x'; }
        }
    }

    for (int i=0; i<r; i++) {
        printf("%s\n", s[i]);
    }
}