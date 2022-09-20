#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

#define MAXN  1005
int dp[MAXN][MAXN];
int m, n, k, a, b, c;

int main(){
    scanf("%d %d", &m, &n);
    scanf("%d", &k);
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    for(int i = 0; i < k; i++){
        scanf("%d %d %d", &a, &b, &c);
        for(int j = m; j >= 0; j--){
            for(int h = n; h >= 0; h--){
                /** 本题限定条件是费用不少于某个特定值，而不是费用小于等于特定值，
                 * 因而对于超过当前费用限额的情况也应给予考虑
                 * 至此我们，根据拾取物品费用与背包费用限额，
                 * 背包问题能被分为三类母题，
                 *      1. 拾取的物品费用，小于等于背包费用限额
                 *      2. 拾取的物品费用，恰好等于背包费用限额
                 *      3. 拾取的物品费用，大于等于背包费用限额
                 * 如果按照物品的获取方程又可以分成：零一背包，多重背包，完全背包，分组背包
                 * 优化方案又包括了逆序遍历少写一个维度以及二进制拆分减少循环量
                **/
                dp[j][h] = min(dp[j][h], dp[max(j - a, 0)][max(h - b, 0)] + c);
            }
        }
    }
    cout << dp[m][n] << endl;
    return 0;
}