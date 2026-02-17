#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

#define MAXN 1500
int n, m, k, dp[MAXN][MAXN], ep[MAXN][MAXN];
int ball, hp;
int main(){
    // 初始化负无穷大
    // memset(dp, 0xcf, sizeof(dp));
    
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 0; i < k; i++){
        cin >> ball >> hp;
        for(int j = n; j >= ball; j--){
            for(int h = m; h >= hp; h--){
                dp[j][h] = max(dp[j][h], dp[j - ball][h - hp] + 1);
            }
        }
    }
    
    // 使得皮卡丘体力值为零的怪物也不会被小智收服
    // 因而能够取到的最大值应为 dp[n][m - 1]

    int ans = -1, t = 0;
    for(int j = 0; j <= n; j++){
        for(int h = 0;  h < m; h++){
            if(dp[j][h] > ans || (ans == dp[j][h] && h < t)){
                ans = dp[j][h], t = h;
            }
        }
    }
    printf("%d %d\n", ans, m - t);
    return 0;
}