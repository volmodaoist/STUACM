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

// 此处一个细节便是 idx = 1 而非 0
int head[MAXN], vex[MAXN], wgt[MAXN], nxt[MAXN], idx = 1;
int vis[MAXN], prec[MAXN], src, dst;
int n, m, a, b, c;


void add_edge(int x, int y, int w) {
    vex[++idx] = y, wgt[idx] = w, nxt[idx] = head[x], head[x] = idx;
}

// Ford-Fulkerson会走很多弯路，基本通过不了任何数据较强的题目
int dfs(int u, int flow = 2e9){
    if(u == dst){
        return flow;
    }
    vis[u] = 1;
    for (int i = head[u]; i; i = nxt[i]){
        int v = vex[i], ret;
        if (wgt[i] && !vis[v] && (ret = dfs(v, min(flow, wgt[i]))) != -1) {
            wgt[i] -= ret;
            wgt[i ^ 1] += ret;
            return ret;
        }
    }
    return -1;
}

llong FF(){
    llong ret, flow = 0;
    while ((ret = dfs(src)) != -1) {
        memset(vis, 0, sizeof(vis));
        flow += ret;
    }
    return flow;
}

int main() {
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    scanf("%d %d %d %d", &n, &m, &src, &dst);
    for (int i = 0; i < m; i++){
        scanf("%d %d %d", &a, &b, &c);
        add_edge(a, b, c);
        add_edge(b, a, 0);
    }
    printf("%lld\n", FF());
    return 0;
}