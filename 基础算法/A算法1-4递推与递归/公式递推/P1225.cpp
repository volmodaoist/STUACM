#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

int n, len = 1, dp[5050][5050];
void big_int_dp(int k){
    for (int i = 1; i <= len; i++){
        dp[k][i] = dp[k - 1][i] + dp[k - 2][i];
    }
    for (int i = 1; i <= len; i++) {
        if(dp[k][i] >= 10){
            dp[k][i + 1] += dp[k][i] / 10;
            dp[k][i] %= 10;
            if(dp[k][len + 1] > 0){
                len++;
            }
        }
    }
}

int main(){ 
    scanf("%d", &n);
    dp[1][1] = 1, dp[2][1] = 2;
    for (int i = 3; i <= n; i++) {
        big_int_dp(i);
    }
    for (int i = len; i >= 1; i--){
        printf("%d", dp[n][i]);
    }
    printf("\n");
    return 0;
}