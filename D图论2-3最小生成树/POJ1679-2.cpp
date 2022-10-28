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

#include <vector>
#include <algorithm>
#include <iostream>
#include <limits>
using namespace std;


typedef long long ill;
typedef unsigned long long ull;
#define  lc(x)  (x<<1)
#define  rc(x)  (x<<1|1)
#define  fi    first
#define  se    second
#define  MAXN  105

int g[MAXN][MAXN];
int dp[MAXN][MAXN];
int dist[MAXN], vist[MAXN], prec[MAXN];
int n, m, a, b, w, kase;

int in_mst[10005];
/**
 * dp[i][j] 数组记录了顶点i~顶点j之间路径的最大权值
 */

int prim(int src) {
    int ans = 0;
    memset(vist, 0, sizeof(vist));
    memset(dist, 0x3f, sizeof(dist));
    dist[src] = 0;
    for (int i = 0; i < n; i++) {
        int t = -1;
        for (int j = 1; j <= n; j++) {
            if (!vist[j] && (t == -1 || dist[t] > dist[j])){
                t = j;
            }
        }
        vist[t] = 1;
        ans += dist[t];
        for (int j = 1; j <= n; j++){
            if(!vist[j] && dist[j] > g[t][j]){
                dist[j] = g[t][j];
                prec[j] = t;
            }
            if (vist[j] && t != j){
                dp[j][t] = dp[t][j] = max(dp[j][prec[t]], dist[t]);
            }
        }
    }
    return ans;
}

//获取最小生成树的顶点与连边
void print_mst(){
    printf("MST = ");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++){
            if (i != j && prec[i] == j){
                printf("(%d, %d)", j, i);
            }
        }
    }
    printf("\n");
}

int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    cin >> kase;
    while (kase--){
        cin >> n >> m;
        memset(g, 0x3f, sizeof(g));
        for (int i = 0; i < m; i++) {
            cin >> a >> b >> w;
            g[a][b] = g[b][a] = w;
        }
        int ans = prim(1);

        /**
         * 首先通过Prim算法获取最小生成树，然后再从MST以外的连边上面添加连边，
         * 然后如此操作必然会使 MST 产生回路，我们假设新加入的连边(u,v)构成了 u->v 闭环
         * 因而我们需要删除 u->v 路径上面的一条边，显然我们需要删掉最大的那条边，
         * 如此得到的生成树便是(非严格)次小生成树，如果次小生成树等于最小生成树，
         * 说明本图的 MST 是不唯一的！
        */

        // 枚举那个不在MST上面的连边，看看是否能够找到连边，满足其权重等于 u ~ v 路径上面最大权重的连边
        // 如此一来，我们的次小生成树也就等于最小生成树了，

        int minv = INT_MAX;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++){
                if (i != j && i != prec[j] && j != prec[i]) {
                    minv = min(minv, g[i][j] - dp[i][j]);
                }
            }
        }
        if(minv == 0){
            cout << "Not Unique!" << endl;
        }else{
            cout << ans << endl;
        }
    }
    return 0;
}