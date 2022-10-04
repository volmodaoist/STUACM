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
#define  MAXN  500005




int heads[MAXN], val[MAXN], wgt[MAXN], nxt[MAXN], idx;
int dist[MAXN], vist[MAXN];
int n, m, a, b, w;

void add_edge(int a, int b, int w) {
    val[idx] = b;
    wgt[idx] = w;
    nxt[idx] = heads[a];
    heads[a] = idx++;
}

void prim(int src){
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
        // 判断是不是孤立节点
        if(dist[t] == INF){
            printf("orz\n");
            return;
        }
        vist[t] = 1;
        ans += dist[t];
        for (int j = heads[t]; ~j; j = nxt[j]) {
            int v = val[j], w = wgt[j];
            if (!vist[v] && dist[v] > w){
                dist[v] = w;
            }
        }
    }
    printf("%d\n", ans);
}


int main() {
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    scanf("%d %d", &n, &m);
    memset(heads, -1, sizeof(heads));
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &w);
        add_edge(a, b, w);
        add_edge(b, a, w);
    }
    prim(1);
    return 0;
}