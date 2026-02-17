#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

#define MAXN 50

int n, r, c, v;
int w[MAXN][MAXN];
int dp[MAXN][MAXN][MAXN];

int main(){
    scanf("%d", &n);
    while(scanf("%d %d %d", &r, &c, &v), r||c||v) w[r][c] = v;
  
    for(int k = 2; k <= 2 * n; k++){
        for(int i1 = 1; i1 <= n; i1++){
            for(int i2 = 1; i2 <= n; i2++){
                int j1 = k - i1, j2 = k - i2;
                if(j1 >= 1 && j1 <= n && j2 >= 1 && j2 <= n){
                    int &y = dp[k][i1][i2];
                    int t = w[i1][j1] + (i1 != i2 ? w[i2][j2] : 0);
                    y = max(y, dp[k - 1][i1 - 1][i2 - 1] + t);
                    y = max(y, dp[k - 1][i1 - 1][i2] + t);
                    y = max(y, dp[k - 1][i1][i2 - 1] + t);
                    y = max(y, dp[k - 1][i1][i2] + t);
                }
            }
        }
    }
    cout << dp[n + n][n][n] << endl;
    return 0;
}