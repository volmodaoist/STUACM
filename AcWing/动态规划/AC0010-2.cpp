#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

#define MAXN 105

int n, m, p, v[MAXN], w[MAXN];
int dp[MAXN][MAXN];

vector<int> edges[MAXN];

void debug_print_dp(){
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= m; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}

void dfs(int u){
    // 遍历当前节点的所有子节点
    for(int son : edges[u]){
        dfs(son);
        // 转移的起点 j = m - v[u]，因为这种做法是在递归返回之后才对 m - v[u] ~ m 这个不分进行更新的
        for(int j = m - v[u]; j >= 0; j--){
            /**
             * 此处枚举体积是因为，如果我们枚举所有当前子树子节点选择与不选择构成的集合，
             * 状态过多，既不不好枚举也容易超时，因而更换思路，只考虑分给每个子节点的体积，
            */
            for(int k = 0; k <= j; k++){
                dp[u][j] = max(dp[u][j], dp[u][j - k]  + dp[son][k]);
            }
        }
    }
    // 所有递归结束之后，那些已被拾取节点需要记得加上当前节点的权值
    for(int j = m; j >= v[u]; j--){
        dp[u][j] = dp[u][j - v[u]] + w[u];
    }
    
    // 如果体积无法放下当前节点，则应置零
    for(int j = 0; j < v[u]; j++){
        dp[u][j] = 0;
    }
    
}

int main(){
    int root = 0;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%d %d %d", &v[i], &w[i], &p);
        if(p == -1){
            root = i;
        }else{
           edges[p].push_back(i);
        }
    }
    dfs(root);
    // debug_print_dp();
    cout << dp[root][m] << endl;
    return 0;
}