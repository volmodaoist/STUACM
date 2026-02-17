#include<bits/stdc++.h>
using namespace std;

#define MAXN 3000


int dp[MAXN], cnt[MAXN];
int n, m, v, w, MOD = 1e9 + 7;

/**
 *  这种解法中，cnt[i]代表体积恰好等于i能够取到的最优方案数，
 *  第一次 WA 是因为忽略了dp[0, m - 1] 当中可能也有等于 dp[m] 价值的拾取方案
 */  
int main(){
    cnt[0] = 1;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &v, &w);
        for(int j = m; j >= v; j--){
            if(dp[j - v] + w > dp[j]){
                dp[j] = dp[j - v] + w;
                cnt[j] = cnt[j - v] % MOD;
            }else if(dp[j - v] + w == dp[j]){
                cnt[j] = (0LL + cnt[j] + cnt[j - v]) % MOD;
            }
        }
    }

    int ans = 0;
    for(int i = 0; i <= m; i++){
        if(dp[i] == dp[m]){
            ans = (0LL + ans + cnt[i]) % MOD;     
        }
    }
    cout << ans << endl;
    return 0;
}


