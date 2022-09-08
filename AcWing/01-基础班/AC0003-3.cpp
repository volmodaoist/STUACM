#include <stdio.h>
#define MAXN     1005
#define min(x,y) (((x)<(y))?(x):(y))
#define max(x,y) (((x)>(y))?(x):(y))

int n, m, v, w, dp[MAXN];

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%d %d", &v, &w);
        for(int j = v; j <= m; j++){
            dp[j] = max(dp[j], dp[j -v] + w);
        }
    }
    printf("%d\n", dp[m]);
    return 0;
}

// dp[i][j] = dp[i - 1][j]; 由于赋值是从右向左运算的