#include <bits/stdc++.h>
using namespace std;

#define MAXN 10000

int n, v;
int vol[MAXN], wgt[MAXN];
int dp[MAXN][MAXN];

int main(){
    scanf("%d %d", &n, &v);
    for(int i = 1; i <= n; i++){
        scanf("%d %d", &vol[i], &wgt[i]);
    }
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= v; j++){
            dp[i][j] = dp[i - 1][j];
            if(j - vol[i] >= 0){
                dp[i][j] = max(dp[i][j],  dp[i - 1][j - vol[i]] + wgt[i]);
            }
        } 
    }
    printf("%d\n", dp[n][v]);
    return 0;  
}