#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

#define  MAXN  100005

vector<int> edges[MAXN];
int n, h[MAXN], dp[MAXN][2], has_father[MAXN];

void dfs(int u){
    dp[u][0] = 0, dp[u][1] = h[u];
    for (int v : edges[u]) {
        dfs(v);
        dp[u][1] += dp[v][0];
        dp[u][0] += max(dp[v][0], dp[v][1]);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d", &h[i]);
    }

    // 一个上司对应多个下属，父子节点之间的关系便是一对多
    for (int i = 1; i < n; i++){
        int l, k;
        scanf("%d %d", &l, &k);
        edges[k].push_back(l);
        has_father[l] = 1;
    }

    int root = 1;
    while(has_father[root]){
        root++;
    }

    dfs(root);
    printf("%d\n", max(dp[root][0], dp[root][1]));
    return 0;
}