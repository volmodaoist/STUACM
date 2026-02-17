#include<bits/stdc++.h>
using namespace std;


#define MAXN 30005

bool dp[MAXN];
int n, m, kase, v[MAXN];


int main(){
    scanf("%d", &kase);
    while(kase--){
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            scanf("%d", &v[i]);           
        }
        
        sort(v + 1, v + n + 1);
        
        memset(dp, 0, sizeof(dp));
        dp[0] = true;
        m = v[n];
        
        
        // 本题的思想非常类似于筛法
        
        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(dp[v[i]]) continue;
            ans++;
            for(int j = v[i]; j <= m; j++){
                dp[j] |= dp[j - v[i]];
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}