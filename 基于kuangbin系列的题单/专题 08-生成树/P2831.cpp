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


#include <stdio.h>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

#define  lc(x)  (x<<1)
#define  rc(x)  (x<<1|1)
#define  MAXN  1005

typedef struct _Edge{
    int a, b, w;
} Edge;
Edge edges[100005];

int g[MAXN][MAXN];
int dp[MAXN][MAXN];
int vist[MAXN], prec[MAXN];
int dist[MAXN];
int n, m, a, b, w, q;


int prim(int src) {
    int ans = 0;
    memset(vist, 0, sizeof(vist));
    memset(dist, 0x3f, sizeof(dist));
    dist[src] = 0;
    for (int i = 0; i < n; i++){
        int t = -1;
        for (int j = 1; j <= n; j++){
            if (!vist[j] && (t == -1 || dist[t] > dist[j])) {
                t = j;
            }
        }
        vist[t] = 1;
        ans += dist[t];
        for (int j = 1; j <= n; j++){
            if (!vist[j] && dist[j] > g[t][j]) {
                dist[j] = g[t][j];
                prec[j] = t;
            }
            if (vist[j] && t != j) {
                dp[j][t] = dp[t][j] = max(dp[j][prec[t]], dist[t]);
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

    while (scanf("%d %d %d", &n, &m, &q) != EOF){
        memset(g, 0x3f, sizeof(g));
        for (int i = 1; i <= m; i++) {
            scanf("%d %d %d", &a, &b, &w);
            edges[i].a = a, edges[i].b = b, edges[i].w = w;
            g[a][b] = g[b][a] = min(w, g[a][b]);
        }
        prim(1);
        // for (int i = 1; i <= n; i++){
        //     for (int j = 1; j <= n; j++){
        //         printf("%d ", dp[i][j]);
        //     }
        //     printf("\n");
        // }
        int idx, cost;
        while (q--) {
            scanf("%d %d", &idx, &cost);
            if(dp[edges[idx].a][edges[idx].b] >= cost){
                printf("Yes\n");
            }else{
                printf("No\n");
            }
        }
    }
    return 0;
}