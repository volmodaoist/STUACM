#define _OJ_ONLINE_JUDGE_
#define	min3(x,y,z)	(min(min(x,y),z))
#define	max3(x,y,z)	(max(max(x,y),z))
#define	ALL(x)  (x.begin()), (x.end())
#define	INS(x)  (inserter(x, x.begin()))
#define	INF	0x3f3f3f3f
#define	MOD	1000000007
#define	PI	3.1415927
#define	EPS	1e-10


#include <bits/stdc++.h>
#include <limits.h>
using namespace std;


typedef long long ill;
typedef unsigned long long ull;
#define  MAXN  1000005

int w[MAXN], n;
ill dp[MAXN];
ill ans = INT_MIN;
vector<int> edges[MAXN];

int dfs(int u, int father){
    dp[u] = w[u];
    for (int v: edges[u]){
        if(v == father)
            continue;
        dfs(v, u);
        dp[u] = max(dp[u] + dp[v], dp[u]);
    }
    return dp[u];
}

int main() {
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d", &w[i]);
    }
    int a, b;
    for (int i = 1; i < n; i++) {
        scanf("%d %d", &a, &b);
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    dfs(1, 0);
    for(int i = 1; i <= n; i++){
        ans =  max(ans, dp[i]);
    }
    printf("%lld\n", ans);
    return 0;
}