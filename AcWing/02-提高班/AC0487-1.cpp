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
            for(int k = 0; k <= j - v[u]; k++){
                dp[u][j] = max(dp[u][j], dp[u][j - k] + dp[son][k]);
            }
        }
    }
}

// 这种解法会超时，但是思想非常有趣
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