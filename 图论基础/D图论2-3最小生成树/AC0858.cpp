#define _OJ_ONLINE_JUDGE_
#define	min3(x,y,z)	(min(min(x,y),z))
#define	max3(x,y,z)	(max(max(x,y),z))
#define	CLEAR(A,x)  (memset(A,x,sizeof(A)))
#define	ALL(x)  (x.begin()), (x.end())
#define	INS(x)  (inserter(x, x.begin()))
#define	INF	0x3f3f3f3f
#define	MOD	1000000007
#define	PI	3.1415927
#define	EPS	1e-10


#include <bits/stdc++.h>
#include <limits>
using namespace std;


typedef long long LLong;
typedef unsigned long long ULL;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
#define  lc(x)  (x<<1)
#define  rc(x)  (x<<1|1)
#define  fi    first
#define  se    second
#define  MAXN  505

int n, m, a, b, w;
int g[MAXN][MAXN], dist[MAXN], vist[MAXN], prec[MAXN];

// 此处 dist[i] 代表顶点 i 到达生成树的最小距离

int prim(int src) {
    int ans = 0;
    memset(vist, 0, sizeof(vist));
    memset(dist, 0x3f, sizeof(dist));
    dist[src] = 0;
    for (int i = 0; i < n; i++){
        int t = -1;
        for (int j = 1; j <= n; j++){
            if(!vist[j] && (t == -1 || dist[t] > dist[j])){
                t = j;
            }
        }
        // 遇到孤立节点则不可能形成一颗最小生成树把所有顶点连起来
        if(dist[t] == INF){
            return -INF;
        }
        vist[t] = 1;
        ans += dist[t];
        for (int j = 1; j <= n; j++){
            if(dist[j] > g[t][j] && !vist[j]){
                dist[j] = g[t][j];
                prec[j] = t;
            }
        }
    }
    return ans;
}
int main() {
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    scanf("%d %d", &n, &m);
    memset(g, 0x3f, sizeof(g));
    memset(prec, -1, sizeof(prec));
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &w);
        g[a][b] = min(g[a][b], w);
        g[b][a] = min(g[b][a], w);
    }
    int t = prim(1);
    if(t == -INF){
        printf("impossible\n");
    }else{
        printf("%d\n", t);
    }
    return 0;
}