#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

#define MAXN 1005

int kase, n, m; 
int pea[MAXN][MAXN], dp[MAXN][MAXN];

void debug_print_dp(int dp[MAXN][MAXN]){
    for(int i = 1; i <= n; i++){
        for(int j  = 1; j <= m; j++){
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }
}

int main(){
    scanf("%d", &kase);
    while(kase--){
        memset(dp, 0, sizeof(dp));
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                scanf("%d", &pea[i][j]);
            }
        }

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + pea[i][j];
            }
        }
        cout << dp[n][m] << endl;
    }
    return 0;
}