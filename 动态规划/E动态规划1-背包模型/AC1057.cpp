#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005
int n, k, w[MAXN], dp[MAXN][105][2];

int main(){
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++){
        scanf("%d", &w[i]);
    }

    memset(dp, 0xcf, sizeof(dp));
    for(int i = 0; i <= n; i++)
        dp[i][0][0] = 0;
        
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k; j++){
            dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + w[i]);
            dp[i][j][1] = max(dp[i - 1][j - 1][0] - w[i],  dp[i - 1][j][1]);
        }
    }
    int ans = 0;
    for(int i = 0; i <= k; i++){
        ans = max(ans, dp[n][i][0]);  
    }
    cout << ans << endl;
    return 0;
}