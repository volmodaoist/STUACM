#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

#define MAXN 305

int n, m;
int g[MAXN][MAXN];
int dp[MAXN][MAXN];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int dfs(int i, int j){
    if(dp[i][j] != 0)
        return dp[i][j];
    dp[i][j] = 1;
    for(int k = 0; k < 4; k++){
        int nx = i + dx[k];
        int ny = j + dy[k];

        // 因为高度差这个条件其实已经杜绝了往回行走的可能，所以不用 vist 数组
        if(nx >= 1 && nx <= n && ny >= 1 && ny <= m && g[nx][ny] < g[i][j]){
            dp[i][j] = max(dp[i][j], dfs(nx, ny) + 1);
        }
    }
    return dp[i][j];
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            scanf("%d", &g[i][j]);
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            ans = max(ans, dfs(i, j));
        }
    }
    printf("%d\n", ans);
    return 0;
}