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


typedef long long llong;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
#define  clz   __builtin_clz
#define  ctz   __builtin_ctz
#define  fi    first
#define  se    second
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
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

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