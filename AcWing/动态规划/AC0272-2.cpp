#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

#define MAXN 3010

int n;
int a[MAXN], b[MAXN];
int dp[MAXN][MAXN];

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)scanf("%d", &a[i]);
    for(int i = 1; i <= n; i++)scanf("%d", &b[i]);
    
    for(int i = 1; i <= n; i++){
        int maxv = 1;
        for(int j = 1; j <= n; j++){
            dp[i][j] = dp[i - 1][j];
            if(b[j] == a[i]){
                dp[i][j] = max(dp[i][j], maxv);   
            }else if(b[j] <  a[i]) {
                maxv = max(maxv, dp[i - 1][j] + 1);
            }
        }
    }
    /**
     * 当我们计算dp[i][j]状态的时候，前面的 dp[i - 1][1 : j-1] 都已算好，
     * 使用一个变量维护  dp[i - 1][1 : j-1] 这个前缀里面的最大值，等到 b[j] = a[i]，再用这个最大值更新即可，
     * 注意 LIS 模型中我们限定了 j < i，但在第二个判断 b[j] < a[i]当中，我们循环里面没有限定 j < i，
     * 但这不要紧，因为 j > i 时刻，此时靠后的 dp 数组尚未计算，数值即为零，即使加上 1，
     * 也仅仅是保证了 b[j] = a[i] 时候公共上升长度至少等于 1 而已！
     */ 
    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans = max(ans, dp[n][i]);
    }
    cout << ans << endl;
    return 0;
}
