#include<bits/stdc++.h>
using namespace std;

#define MAXN 300

int kase, n;
int dp[MAXN], hgt[MAXN], path[MAXN];

int main(){
    scanf("%d", &kase);
    while(kase--){
        scanf("%d", &n);
        memset(path, -1, sizeof(path));
        for(int i = 1; i <= n; i++){
            scanf("%d", &hgt[i]),  dp[i] = 1;
        }

    
        int ans = 0, idx = 0;
        for(int i = 1; i <= n; i++){
            for(int j  = 1; j < i;  j++){
                if(hgt[j] > hgt[i] && dp[j] + 1 > dp[i]){
                    dp[i] = dp[j] + 1;
                    path[i] = j;
                }
            }
            ans = max(ans, dp[i]);
        }
        
        // 找出最长下降子序列，并从这个位置开始打印路径
        // for(int i = 1; i <= n; i++){
        //     if(dp[i] > ans){
        //         ans = dp[i];
        //         idx = i;
        //     }
        // }
        // 打印路径
        // int curr = path[idx];
        // while(curr != -1){
        //     printf("hgt(%d) = %d\n", curr, hgt[curr]);
        //     curr = path[curr];
        // }
        
        reverse(hgt + 1, hgt + 1 + n);
        for(int i = 1; i <= n; i++)
            dp[i] = 1;
    
        for(int i = 1; i <= n; i++){
            for(int j  = 1; j < i;  j++){
                if(hgt[j] > hgt[i] && dp[j] + 1 > dp[i]){
                    dp[i] = dp[j] + 1;
                    path[i] = j;
                }
            }
            ans = max(ans, dp[i]);
        }
        
        cout << ans << endl;
    }
    return 0;
}