#include<bits/stdc++.h>
using namespace std;

#define MAXN 100005

int kase;
int n, s[MAXN], dp[MAXN][2];

int main(){
    scanf("%d", &kase);
    while(kase--){
        scanf("%d", &n);
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= n; i++){
            scanf("%d", &s[i]);
        }
        for(int i = 1; i <= n; i++){
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = dp[i - 1][0] + s[i];
        }
        printf("%d\n", max(dp[n][1], dp[n][0]));
    }
    return 0 ;
}