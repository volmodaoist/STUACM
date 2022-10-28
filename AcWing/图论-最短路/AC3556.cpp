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
#define  MAXN  55

typedef struct Egde{
    int a, b, c;
} Edge;
Edge edges[2500];
int g[MAXN][MAXN];
int dist[MAXN], vist[MAXN];
int kase, n, m, k, a, b, c, t;

int dijstra(int src, int dst){
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
        for (int j = 1; j <= n; j++) {
            dist[j] = min(dist[j], dist[t] + g[t][j]);
        }
    }
    return (dist[dst] == INF) ? -1 : dist[dst];
}


void debug_check_graph(){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            printf("%d ", g[i][j] == INF ? 0 : g[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


int main() {
#ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    cin >> kase;
    while (kase--){
        memset(g, 0x3f, sizeof(g));
        scanf("%d %d %d", &n, &m, &k);
        for (int i = 1; i <= m; i++) {
            scanf("%d %d %d", &a, &b, &c);
            edges[i] = {a, b, c};
            g[a][b] = min(g[a][b], c);
            g[b][a] = min(g[b][a], c);
        }
        printf("%d\n", dijstra(1, n));
        // debug_check_graph();

        for (int i = 0; i < k; i++){
            scanf("%d", &t);
            g[edges[t].a][edges[t].b] = INF;
            g[edges[t].b][edges[t].a] = INF;
        }
        // debug_check_graph();
        printf("%d\n", dijstra(1, n));
    }

    return 0;
}