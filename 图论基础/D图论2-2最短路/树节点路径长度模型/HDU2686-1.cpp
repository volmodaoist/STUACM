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


typedef long long ill;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
#define  lc(x)  (x<<1)
#define  rc(x)  (x<<1|1)
#define  fi    first
#define  se    second
#define  MAXN  50005

vector<ii> edges[MAXN];
int ft[MAXN][25], dep[MAXN], path[MAXN];
int n, q, a, b, w, kase;

void dfs(int u, int father, int father_weight) {
    ft[u][0] = father;
    dep[u] = dep[father] + 1;
    path[u] = path[father] + father_weight;
    for (int i = 1; i <= 20;  i++){
        ft[u][i] = ft[ft[u][i - 1]][i - 1];
    }
    for(auto &vex_wgt: edges[u]){
        int v = vex_wgt.first, w = vex_wgt.second;
        if(v != father){
            dfs(v, u, w);
        }
    }
}

int lca(int u, int v){
    if(dep[u] < dep[v])
        swap(u, v);
    for (int i = 20; i >= 0; i--) {
        if(dep[ft[u][i]] >= dep[v]){
            u = ft[u][i];
        }
    }
    if(u == v) return v;
    for (int i = 20; i >= 0; i--){
        if (ft[u][i] != ft[v][i]) {
            u = ft[u][i], v = ft[v][i];
        }
    }
    return ft[u][0];
}

int main(){ 
    #ifdef _OJ_ONLINE_JUDGE_
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);
    #endif

    scanf("%d", &kase);
    while(kase--){
        scanf("%d %d", &n, &q);
        memset(ft, 0, sizeof(ft));
        memset(dep, 0, sizeof(dep));
        memset(path, 0, sizeof(path));
        for (int i = 1; i <= n; i++)
            edges[i].clear();
        for (int i = 1; i < n; i++) {
            scanf("%d %d %d", &a, &b, &w);
            edges[a].emplace_back(b, w);
            edges[b].emplace_back(a, w);
        }
        dfs(1, 0, 0);
        for (int i = 0; i < q; i++) {
            scanf("%d %d", &a, &b);
            printf("%d\n", path[a] + path[b] - 2 * path[lca(a, b)]);
        }
    }

    return 0;
}