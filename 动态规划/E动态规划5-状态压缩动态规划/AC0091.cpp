#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

#define MAXN 20
#define MAXS 2000000 

int n;
int g[MAXN][MAXN];
int dp[MAXS][MAXN];

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j  < n; j++){
            scanf("%d", &g[i][j]);
        }
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[1][0] = 0; 
    for(int i = 1; i < 1 << n; i++){
        for(int j = 0; j < n; j ++){
            if(i >> j & 1){
                for(int k = 0; k < n; k++){
                    // 因为 i - (1 << j) 必然小于i，所以相当是用状态i之前的状态的更新i 
                    if((i - (1 << j)) >> k & 1){
                        dp[i][j] = min(dp[i][j], dp[i - (1 << j)][k] + g[k][j]);
                    }
                }
            }
        }
    }
    printf("%d\n", dp[(1 << n) - 1][n - 1]);
    return 0;
}