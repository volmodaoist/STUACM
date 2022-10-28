#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

#define MAXN 400

int n;
int b[MAXN];
int s[MAXN];
int dp[MAXN][MAXN];

void debug_print_dp(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }
}


void dp_from_top2bottom(){
    scanf("%d", &n);
    memset(dp, 0x3f, sizeof(dp));
    for(int i = 1; i <= n; i++){
        scanf("%d", &b[i]);
        s[i] = s[i - 1] + b[i], dp[i][i] = 0;
    }
    for(int len = 2; len <= n; len++){
        for(int i = 1; i + len - 1 <= n; i++){
            int j = i + len - 1; 
            for(int k = i; k < j; k++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + (s[j] - s[i-1]));
            }
        }
    }
    // debug_print_dp();
    printf("%d\n", dp[1][n]);
}

void dp_from_bottom2top(){
    scanf("%d", &n);
    memset(dp, 0x3f, sizeof(dp));
    for(int i = 1; i <= n; i++){
        scanf("%d", &b[i]);
        s[i] = s[i - 1] + b[i], dp[i][i] = 0;
    }
    for(int i = n; i >= 1; i--){
        for(int j  = i; j <= n; j++){
            if(i !=j ){
                for(int k = i; k < j; k++){
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + (s[j] - s[i-1]));
                }
            }
        }
    }
    // debug_print_dp();
    printf("%d\n", dp[1][n]);
}

int main(){
    dp_from_top2bottom();
    return 0;
}