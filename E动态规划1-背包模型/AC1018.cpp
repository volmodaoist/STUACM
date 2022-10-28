#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

#define MAXN 1005

int kase, n, m; 
int cost[MAXN][MAXN], dp[MAXN][MAXN];

void debug_print_dp(int dp[MAXN][MAXN]){
    for(int i = 1; i <= n; i++){
        for(int j  = 1; j <= n; j++){
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }
}

int main(){
    memset(dp, 0x3f, sizeof(dp));
    dp[0][1] = dp[1][0] = dp[0][0] = 0;
    
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            scanf("%d", &cost[i][j]);
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + cost[i][j];
        }
    }
    // debug_print_dp(dp);
    cout << dp[n][n] << endl;
    return 0;
}