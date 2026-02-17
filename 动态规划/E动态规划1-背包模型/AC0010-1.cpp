#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

#define MAXN 105
int n, m, p;
int v[MAXN], w[MAXN];
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
    // 在容量足够的情况之下，当前节点是必选的，否则无法选择其下所有子节点
    for(int j = v[u]; j <= m; j++){
        dp[u][j] = w[u];
    }
    /**
     * 遍历当前节点的所有子节点（遍历所有组）
     * 当前节点 u 走到以其为根的整棵子树的每个子节点的路径，构成一个组，我们要在组内选一个最大的
    */
    for(int son : edges[u]){ //遍历所在孩子节点
        dfs(son);
        for(int j = m; j >= v[u]; j--){ // 遍历背包的容量
            for(int k = 0; k <= j - v[u]; k++){ // 由于当前节点必选，所有子节点能用的容量只有 j - v[u]
                dp[u][j] = max(dp[u][j], dp[u][j - k]  + dp[son][k]);
            }
        }
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

    cout << dp[root][m] << endl;
    return 0;
}