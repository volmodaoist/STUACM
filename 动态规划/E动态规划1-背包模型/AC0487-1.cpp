#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

#define MAXN 32010

vector<int> edges[MAXN];

int n, m, super_root;
int v[MAXN], p[MAXN], q, dp[100][MAXN];

void dfs(int u){
    for(int j = v[u]; j <= m; j++){
        dp[u][j] = v[u] * p[u];
    }
    for(int son: edges[u]){
        dfs(son);
        // 此处枚举体积的循环，带来的复杂度非常大！这种方法思路正确但是必定超时！
        for(int j = m; j >= v[u]; j--){
            /** 
             * 其实枚举背包容积每次减少1，分给子节点每次分配1，这种做法非常低效，很多状态其实都不会发生转移！
             * 对于所有物品的体积(也即本题的价格)来说，会发生转移的状态，都是所有物品体积的最大公因数的若干倍！
             * 因而背包容积有关的枚举，其枚举步长均可变为它们的最大公因数！
            */
            for(int k = 0; k <= j - v[u]; k++){
                dp[u][j] = max(dp[u][j], dp[u][j - k] + dp[son][k]);
            }
        }
    }
}

// 这种解法会超时，但是思想非常有趣, 那么应该如何优化呢？
// 虚设一个超级节点，把其它所有主件都挂接到这个超级节点上面，然后对其跑一趟树形背包
int main(){
    scanf("%d %d", &m, &n);
    for(int i = 1; i <= n; i++){
        scanf("%d %d %d", &v[i], &p[i], &q);
        if(q == 0){
            edges[super_root].push_back(i);
        }else{
            edges[q].push_back(i);
        }
    }
    
    dfs(super_root);
    cout << dp[super_root][m] << endl;
    return 0;
}