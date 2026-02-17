#include <bits/stdc++.h>
#include <limits.h>

using namespace std;
#define MAXN 6005

int n, a, b;
int has_father[MAXN];
int happy[MAXN], dp[MAXN][2];

vector<int> edges[MAXN];

int dfs(int u){
    dp[u][1] = happy[u];
    for(auto v: edges[u]){
        // dfs 走到最底部向上返回信息的过程中才能得知各个子节点的快乐值
        dfs(v);
        dp[u][0] += max(dp[v][1], dp[v][0]);
        dp[u][1] += dp[v][0];
    }
    return max(dp[u][1], dp[u][0]);
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &happy[i]);
    }
    
    for(int i = 1;  i < n; i++){
        scanf("%d %d", &a, &b);
        edges[b].push_back(a);
        has_father[a] = 1;
    }
    
    // 由于题目没有给出父节点，我们需要自行计算
    int root =  1;
    while(has_father[root]){
        root++;
    }
    
    printf("%d\n", dfs(root));
    
    return 0;
}