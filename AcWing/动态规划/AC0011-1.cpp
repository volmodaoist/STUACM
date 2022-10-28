#include<bits/stdc++.h>
using namespace std;

#define MAXN 3000


int dp[MAXN], cnt[MAXN];
int n, m, v, w, MOD = 1e9 + 7;

/**
 * 其中 dp[j] 代表体积不超过 i 能够取到的最大价值， 
 * 其中 cnt[i] 代表体积不超过 i 能够取到的最优方案数，
 * 因为啥都不取也是一种方案，故将所有 cnt[i] 初始化设为 1
 * 
*/
int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i <= m; i++)
        cnt[i] = 1;
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
    cout << cnt[m] << endl;
    return 0;
}


