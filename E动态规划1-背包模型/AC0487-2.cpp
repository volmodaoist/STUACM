#include<bits/stdc++.h>
using namespace std;

#define MAXN 32010

vector<int> edges[MAXN];

int n, m, cnt, super_root;
int v[MAXN], p[MAXN], q, dp[80][MAXN];

void dfs(int u){
    // 修改枚举步长
    for(int j = v[u]; j <= m; j += cnt){
        dp[u][j] = v[u] * p[u];
    }
    /**  
     * 修改枚举步长，因为所有物品的价值都是它们最大公因数的若干倍，
     * 只有分给子节点的可用容积是其公因数若干倍的时候才能发生转移!
    */
    for(int son: edges[u]){
        dfs(son); 
        for(int j = m; j >= v[u]; j -= cnt){
            for(int k = 0; k <= j - v[u]; k += cnt){
                dp[u][j] = max(dp[u][j], dp[u][j - k] + dp[son][k]);
            }
        }
    }
}

int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}

int main(){
    scanf("%d %d", &m, &n);
    for(int i = 1; i <= n; i++){
        scanf("%d %d %d", &v[i], &p[i], &q);

        // 这是非常重要的一个优化
        cnt = cnt ? gcd(cnt, v[i]) : v[i];

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