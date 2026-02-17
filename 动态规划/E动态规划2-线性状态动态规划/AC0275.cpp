#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

#define MAXN 55

int n, m;
int w[MAXN][MAXN];
int dp[MAXN << 1][MAXN][MAXN];

void debug_print(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            printf("%d ", w[i][j]);
        }
        printf("\n");
    } 
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            scanf("%d", &w[i][j]);
        }
    }
    
 
    for(int k = 2; k <= (n + m); k++){
        for(int i1 = 1; i1 <= n; i1++){
            for(int i2 = 1; i2 <= n; i2++){
                int j1 = k - i1, j2 = k - i2;
                if(j1 >= 1 && j1 <= m && j2 >= 1 & j2 <= m){
                    int &y = dp[k][i1][i2];
                    int t = w[i1][j1] + (i1 != i2 ? w[i2][j2] : 0);
                    
                    y = max(y, dp[k - 1][i1 - 1][i2 - 1] + t);
                    y = max(y, dp[k - 1][i1 - 1][i2] + t);
                    y = max(y, dp[k - 1][i1][i2 - 1] + t);
                    y = max(y, dp[k - 1][i1][i2] + t);
                    
                }
            }
        }
    }
    cout << dp[n + m][n][n] << endl;
    return 0;
}