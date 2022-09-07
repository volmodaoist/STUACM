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
#define  MAXN  50005

vector<ii> edges[MAXN];
int ft[MAXN], dep[MAXN], path[MAXN], siz[MAXN], hev[MAXN], top[MAXN];
int n, q, a, b, w, kase;

// siz 存储子树大小，hev 存储重子树节点
void tree_build(int u, int father, int father_weight) {
    ft[u] = father, siz[u] = 1;
    dep[u] = dep[father] + 1, path[u] = path[father] + father_weight;
    for(auto &vex_wgt: edges[u]){
        int v = vex_wgt.first, w = vex_wgt.second;
        if(v == father)
            continue;
        tree_build(v, u, w);
        siz[u] += siz[v];
        if(siz[hev[u]] < siz[v]) hev[u] = v;
    }
}

void tree_decomposition(int u, int t){
    top[u] = t;
    if(!hev[u]) return;
    tree_decomposition(hev[u], t);
    for(auto &vex_wgt: edges[u]){
        int v = vex_wgt.first, w = vex_wgt.second;
        if(v == ft[u] || v == hev[u])
            continue;
        tree_decomposition(v, v); // 轻链的链头是其本身
    }
}


int lca(int u, int v){
    while(top[u] != top[v]){
        if(dep[top[u]] < dep[top[v]]){
            swap(u, v);
        }
        u = ft[top[u]];
    }
    return dep[u] < dep[v] ? u : v;
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
        memset(siz, 0, sizeof(siz));
        memset(hev, 0, sizeof(hev));
        memset(top, 0, sizeof(top));

        for (int i = 1; i <= n; i++)
            edges[i].clear();
        for (int i = 1; i < n; i++) {
            scanf("%d %d %d", &a, &b, &w);
            edges[a].emplace_back(b, w);
            edges[b].emplace_back(a, w);
        }
        tree_build(1, 0, 0);
        tree_decomposition(1, 0);
        for (int i = 0; i < q; i++) {
            scanf("%d %d", &a, &b);
            printf("%d\n", path[a] + path[b] - 2 * path[lca(a, b)]);
        }
    }

    return 0;
}