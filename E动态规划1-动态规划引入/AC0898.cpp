#include <bits/stdc++.h>
using namespace std;

#define MAXN 505
int n;
int g[MAXN][MAXN], dp[MAXN][MAXN];

void debug_print(int  g[][MAXN]){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            printf("%d ", g[i][j]);
        }
        printf("\n");
    }
}


void solve_from_bottom2top(){
     scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            scanf("%d", &g[i][j]);
        }
    }
    for(int i = 1; i <= n; i++)
        dp[n][i] = g[n][i];
    for(int i = n - 1; i >= 1; i--){
        for(int j = 1; j <= n; j++){
            dp[i][j] = g[i][j] + max(dp[i + 1][j], dp[i + 1][j + 1]);
        }
    }
    // debug_print(dp);
    printf("%d\n", dp[1][1]);
}


void solve_from_top2bottom() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            scanf("%d", &g[i][j]);
        }
    }
    
    memset(dp, 128, sizeof(dp));
    dp[0][0] = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            dp[i][j] = g[i][j] + max(dp[i - 1][j], dp[i - 1][j - 1]);
        }
    }
    
    int ans = INT_MIN;
    for(int  i = 1; i <= n; i++){
        ans = max(ans, dp[n][i]);
    }
    printf("%d\n", ans);
}


// 自底向上是需要考虑的边界更少
int main(){
    solve_from_bottom2top();
    return 0;
}