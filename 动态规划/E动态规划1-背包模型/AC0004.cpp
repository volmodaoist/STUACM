#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

#define MAXN 1005

int n, m, v, w, s;
int dp[MAXN][MAXN];
int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%d %d %d", &v, &w, &s);
        for(int j = 0; j <= m; j++){
            dp[i][j] = dp[i - 1][j];
            for(int k = 0; k <= s; k++){
                if(j >= k * v){
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - k * v] + k * w);
                }
            }
        } 
    }
    printf("%d\n", dp[n][m]);
    return 0;
}