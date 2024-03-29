#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

typedef long long ill;
typedef unsigned long long ull;
#define  MAXN  1000005


// vector<int> edges[MAXN];
// 本题时间卡得比较紧，使用连边表会被TLE

ill dp[MAXN][2];
int w[MAXN], vis[MAXN], r1, r2, n;
int head[MAXN], val[MAXN], nxt[MAXN], idx;

void add_edge(int u, int v){
    val[idx] = v, nxt[idx] = head[u], head[u] = idx++;
}

void find(int u, int r){
    vis[u] = 1;
    for (int i = head[u]; ~i; i = nxt[i]) {
        int v = val[i];
        if (v == r) {
            r1 = u, r2 = r;
            return;
        }
        if(!vis[v]) find(v, r);
    }
}

ill dfs(int u, int r){
    dp[u][0] = 0, dp[u][1] = w[u];
    for (int i = head[u]; ~i; i = nxt[i]) {
        int v = val[i];
        if (v == r)
            continue;
        dfs(v, r);
        dp[u][0] += max(dp[v][0], dp[v][1]);
        dp[u][1] += dp[v][0];
    }
    return dp[u][0];
}


int main() {
    scanf("%d", &n);
    memset(head, -1, sizeof(head));
    for (int u = 1, v = 0; u <= n; u++) {
        scanf("%d %d", &w[u], &v);
        add_edge(v, u);
    }

    // debug_edges();

    // 拆边成林之后，本题其实就是「P1352. 没有上司的舞会」简单变体
    ill ans = 0;
    for (int u = 1; u <= n; u++) {
        r1 = r2 = 0;
        find(u, u);
        if (r1) {
            ans += max(dfs(r1, r1), dfs(r2, r2));
        }
    }

    printf("%lld\n", ans);
    return 0;
}