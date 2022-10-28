#include <stdio.h>
#define MAXN     1005
#define min(x,y) (((x)<(y))?(x):(y))
#define max(x,y) (((x)>(y))?(x):(y))

int n, m, v, w;
int dp[MAXN][MAXN] ;

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%d %d", &v, &w);
        for(int j = 0; j <= m; j++){
            dp[i][j] = dp[i - 1][j];
            if(j >= v){
                dp[i][j] = max(dp[i][j], dp[i][j - v] + w);                   
            }
        }
    }
    printf("%d\n", dp[n][m]);
    return 0;
}