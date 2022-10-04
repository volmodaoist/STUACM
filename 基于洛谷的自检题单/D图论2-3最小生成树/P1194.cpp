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


typedef long long llong;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
#define  lc(x)  (x<<1)
#define  rc(x)  (x<<1|1)
#define  fi    first
#define  se    second
#define  MAXN  505

int a, b;
int g[MAXN][MAXN], dist[MAXN], vist[MAXN];

int prim(int src) {
    int mst = 0;
    memset(vist, 0, sizeof(vist));
    memset(dist, 0x3f, sizeof(dist));
    dist[src] = a;
    for (int i = 1; i <= b; i++) {
        int t = -1;
        for (int j = 1; j <= b; j++){
            if(!vist[j] && (t == -1 || dist[t] > dist[j])){
                t = j;
            }
        }
        // 是否需要考虑孤立节点呢？
        vist[t] = 1;
        mst += dist[t];
        for (int j = 1; j <= b; j++) {
            if(!vist[j] && dist[j] > g[t][j]){
                dist[j] = g[t][j];
            }
        }
    }
    return mst;
}

int main() {
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    scanf("%d %d", &a, &b);
    for (int i = 1; i <= b; i++){
        for (int j = 1; j <= b; j++){
            scanf("%d", &g[i][j]);
            if(g[i][j] == 0 || g[i][j] > a){
                g[i][j] = a;
            }
        }
    }
    
    printf("%d\n", prim(1));

    return 0;
}