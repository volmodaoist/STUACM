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
    
    // 若想计算最长上升子序列必须规定结尾，因而状态方程 dp[i][j]，
    // a[1:i] 与 b[1:j]，并以 b[j] 结尾的，最长上升子序列，
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            // 类似于背包问题，不管a[i]是否等于b[j]都先照抄上一行
            dp[i][j] = dp[i - 1][j];
            if(a[i] == b[j]){
                /**
                 * 如果 a[i] = b[i]，公共上升子序列长度至少等于 1，再看状态如何转移，
                 * 由于已经知道 a[i] = b[i]， 故考虑前一个最优状态，例如 dp[i - 1][j - 1]，
                 * 然而 dp[i - 1][j - 1]代表的、使用 b[j - 1] 作为结尾的，并不一定就是最优状态，
                 * 回想一下LIS 模型，我们需要枚举dp[i - 1][1 ~ j-1]，看看以谁结尾最长，再用它更新状态
                */ 
                dp[i][j] = max(dp[i][j], 1);
                for(int k = 1; k < j; k++){
                    if(b[k] < b[j]){
                        dp[i][j] = max(dp[i][j], dp[i - 1][k] + 1);
                    }
                }
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans = max(ans, dp[n][i]);
    }
    // 上面这种做法用到了三种循环，对于上千的数据量是会超时的，
    cout << ans << endl;
    return 0;
}
