#include <stdio.h>
#define MAXN     1005
#define min(x,y) (((x)<(y))?(x):(y))
#define max(x,y) (((x)>(y))?(x):(y))

int n, m, v, w;
int dp[MAXN][MAXN] ;

// 这种做法无法通过 TLE
int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%d %d", &v, &w);
        for(int j = 0; j <= m; j++){
            dp[i][j] = dp[i - 1][j];
            for(int k = 0; k * v <= j; k++){
                if(j - k * v >= 0){
                    dp[i][j] = max(dp[i][j], dp[i][j  - k * v] + k * w);

                }
            }
        }
    }
    printf("%d\n", dp[n][m]);
    return 0;
}